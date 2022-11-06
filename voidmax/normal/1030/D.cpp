// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")    
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
#include <iomanip> 
#include <chrono>
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((string(FILENAME) + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((string(FILENAME) + ".out").c_str(), "w", stdout)
using namespace std;
        
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; } 
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const pair<T, U> &_p) { _out << _p.first << ' ' << _p.second; return _out; }
template<typename T, typename U> inline istream &operator>> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const vector<T> &_v) { if (_v.empty()) { return _out; } _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline istream &operator>> (istream &_in, vector<T> &_v) { for (auto &_i : _v) { _in >> _i; } return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const unordered_map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
 
typedef long long base;       
typedef pair<int, int> point;

const int MAXN = 1e6 + 1;

long long n, m, k;

long long gcd(long long a, long long b) {
	return a ? gcd(b % a, a) : b;
}

long long a, b;
vector<long long> dev[2];

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    cin >> n >> m >> k;
   	long long s = n * m;
    auto g = gcd(s, k);
    s /= g;
    k /= g;
    if (k > 2) {
    	cout << "NO\n";
    	return 0;
    }
    // cout << "YES\n";
    if (k == 1) {
    	s *= 2;
    }
    if (s > n * m) {
    	cout << "NO" << endl;
    	return 0;
    }
    for (long long i = 1; i * i <= n; ++i) {
    	if (n * 2 % i == 0) {
    		dev[0].pb(i);
    		dev[0].pb(n * 2 / i);
    	}
    }
    for (long long i = 1; i * i <= m; ++i) {
    	if (m % i == 0) {
    		dev[1].pb(i);
    		dev[1].pb(m / i);
    	}
    }
    for (long long i : dev[0]) {
    	for (long long j : dev[1]) {
    		if (s % (i * j) == 0) {
    			long long a = i * j;
    			long long b = s / (i * j);
    			if (a <= n && b <= m) {
    				cout << "YES" << endl;
    				cout << 0 << ' ' << 0 << endl;
    				cout << a << ' ' << 0 << endl;
    				cout << 0 << ' ' << b << endl;
    				return 0;
    			}
    			swap(a, b);
    			if (a <= n && b <= m) {
    				cout << "YES" << endl;
    				cout << 0 << ' ' << 0 << endl;
    				cout << a << ' ' << 0 << endl;
    				cout << 0 << ' ' << b << endl;
    				return 0;
    			}
    		}
    	}
    }
    cout << "NO" << endl;
}