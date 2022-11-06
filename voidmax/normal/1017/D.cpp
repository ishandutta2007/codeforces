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
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
// #pragma GCC optimize("unroll-loops")    
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
 
typedef long double base;        
typedef pair<int, int> point;
 
const int N = 1 << 12;

int n, m, k;
int w[12];
int cost[N];
int cnt[N];
vector<pair<short int, short int>> bucket[101];
int ans[N][101];

int main() {
	ios::sync_with_stdio(0);
	srand(time(0));
	//read("input");
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		cin >> w[i];
	}
	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		int k = 0;
		for (auto c : s) {
			k <<= 1;
			k += (c - '0');
		}
		++cnt[k];
	}	
	for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0; j < n; ++j) {
			if (((i >> j) & 1) == 0) {
				cost[i] += w[j];
			}
		}
	}
	for (int i = 0; i < (1 << n); ++i) {
		for (int j = i; j < (1 << n); ++j) {
			if (cost[i ^ j] <= 100) {
				bucket[cost[i ^ j]].pb({i, j});
			}
		}
	}
	for (int w = 0; w <= 100; ++w) {
		for (int i = 0; i < (1 << n); ++i) {
			if (w) ans[i][w] += ans[i][w - 1];
		}
		for (auto &i : bucket[w]) {
			//cout << i.x << ' ' << i.y << ' ' << w << endl;
			ans[i.x][w] += cnt[i.y];
			if (i.x != i.y) {
				swap(i.x, i.y);
				ans[i.x][w] += cnt[i.y];
			}
		}
	} 
	for (int i = 0; i < k; ++i) {
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		int r = 0;
		for (auto c : s) {
			r <<= 1;
			r += (c - '0');
		}
		int w;
		cin >> w;
		// cout << ans[r] << endl;
		// cout << pref[r] << endl;
		cout << ans[r][w] << '\n';
	}

	
}