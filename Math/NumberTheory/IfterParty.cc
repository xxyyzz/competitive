/* Author: Ankit Sultana
 * Problem id: 1014
 * * * * * * * * * */
#include <iostream>
#include <cstring>
#include <limits>
#include <cmath>
#include <fstream>
#include <map>
#include <algorithm>
#include <iterator>
#include <vector>
#include <set>
#include <cassert>
#define LL long long
#define PB push_back
#define SWAP(a,b) a^=b,b^=a,a^=b
#define MP make_pair
#define vi vector<int>
#define vll vector<LL>
#define REP(i,n)	for(__typeof(n) i = 0; i < n; i++)
#define REP1(i,n)	for(__typeof(n) i = 1; i <= n; i++)
#define REPc(i,j,n)	for(__typeof(n) i = j; i <= n; i++)
#define FOR(i,c) for(__typeof(c.begin()) i = c.begin(); i != c.end(); i++)
#define F first
#define S second
#define smax(a, b) a = max(a, b)
#define smin(a, b) a = min(a, b)
#define mod 1000000007ll
#define SZ(a) int(a.size())
#define SZll(a) (LL)(a.size())
#define DECODE(x) int(x-'0')
#define ENCODE(x) char(x+'0')
#define what_is(x) cout<<#x<<" is "<<x<<'\n'
#define pii pair<int, int>
#define pll pair<LL, LL>
#define pil pair<int, LL>
#define pli pair<LL, int>

using namespace std;

template<typename T> T gcd(T a, T b) { return b == 0?a: gcd(b, a % b); }
template<typename T> T LCM(T a, T b) { return a*(b/gcd(a, b)); }
template<typename T> T expo(T b, T e, const T &m){if(e <= 1)return e == 0?1: b;\
	return (e&1) == 0?expo((b*b)%m, e>>1, m): (b*expo((b*b)%m, e>>1, m))%m;}
template<typename T> T modinv(T a) { return expo(a, mod-2, mod); }
template<class T, class S> std::ostream& operator<<(std::ostream &os, const std::pair<T, S> &t) {
	os<<"("<<t.first<<", "<<t.second<<")";  
	return os;
}
template<class T> std::ostream& operator<<(std::ostream &os, const std::vector<T> &t) {
	os<<"["; FOR(it,t) { if(it != t.begin()) os<<", "; os<<*it; } os<<"]";
	return os;
}
namespace variadic {
	template<typename T> T min(T v) { return v; }
	template<typename T, typename... Args> T min(T f, Args... args) {
		return std::min(f, min(args...)); }
	template<typename T> T max(T v) { return v; }
	template<typename T, typename... Args> T max(T f, Args... args) { 
		return std::max(f, max(args...)); }
}

int main()
{
	ios_base::sync_with_stdio(false);
	LL l, p;
	int t;
	cin >> t;
	REP1(tc,t) {
		cin >> p >> l;
		LL temp = p - l;
		LL x = 1;
		set<LL> res;
		cout << "Case " << tc << ": ";
		while(x*x <= temp) {
			if(x*x == temp) {
				if(x > l)
					res.insert(x);
				break;
			}
			if(temp % x == 0) {
				if(x > l) {
					res.insert(x);  
				}
				if(temp % (temp / x) == 0 && temp/x > l) {
					res.insert(temp/x);
				}
			}
			x++;
		}
		if((int)res.size() == 0) {
			cout << "impossible";
		} else {
			set<LL>::iterator it = res.begin();
			while(true) {
				cout << *it;
				it++;
				if(it == res.end())	break;
				cout << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}
