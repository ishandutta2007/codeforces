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
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
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
      
const int MAXN = 2e5 + 1;

int n;
long long len;
int a[MAXN];
int b[MAXN];

int pref[MAXN * 3];
int v[MAXN];

long long get(int i) {
	int d = i / n;
	if (i < 0) --d;
	return len * d + a[i - d * n];
}

bool check(int d) {
	for (int i = 0; i < n * 3; ++i) {
		pref[i] = 0;
	}
	int L = -n, R = 0;
	//cout << "?" << d << endl;
	for (int i = 0; i < n; ++i) {
		v[i] = 0;
		while (abs(get(L) - b[i]) > d) {
			//cout << get(L) << ' ' << b[i] << ' ' << L << endl;
			if (L > n * 2) return false; 
			++L;
		}

		chkmax(R, L);
		while (abs(get(R) - b[i]) <= d) {
			++R;
		}
		if (R - L >= n) {
			//cout << "_" << endl;
			pref[0]++;
			pref[n]--;
		} else {
			pref[L + n * 2 - i]++;
			pref[R + n * 2 - i]--;
		}
		//cout << L - i << ' ' << R - i << endl;
	}
	//cout << "Hi" << endl;
	int b = 0;
	for (int i = 0; i < n * 3; ++i) {
		b += pref[i];
		v[i % n] += b;
	}
	// for (int i = 0; i < n; ++i) {
	// 	cout << v[i] << ':';
	// } cout << endl;
	for (int i = 0; i < n; ++i) {
		if (v[i] == n) return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	//freopen("input.in", "r", stdin);
	cin >> n >> len;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	sort(a, a + n);
	sort(b, b + n);
	int L = -1, R = len;
	while (R - L > 1) {
		int M = (L + R) >> 1;
		if (check(M)) {
			R = M;
		} else {
			L = M;
		}
	}
	cout << R << endl;
}