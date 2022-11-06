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
// 2
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
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const pair<T, U> &_p) { _out << "(" << _p.first << ' ' << _p.second << ")"; return _out; }
template<typename T, typename U> inline istream &operator>> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const vector<T> &_v) { if (_v.empty()) { return _out; } _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline istream &operator>> (istream &_in, vector<T> &_v) { for (auto &_i : _v) { _in >> _i; } return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const unordered_map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
     
const int N = 2e5 + 1;

int n, m;
unordered_map<int, int> who[8];
int a[N];
vector<int> p[N];
int L[N][15];


const int M = 1e4 + 1;
vector<int> prime;
bool cool[M];

const int Q = 1e9 + 7;

vector<pair<int, int>> ask;
vector<int> ans;

const int LOG = 20;

int g[N];
int t[LOG][N];

int get(int L, int R) {
	--L;
	int s = g[R - L] - 1;
	return max(t[s][L], t[s][R - (1 << s)]) + 1;
}

int main() {
	ios::sync_with_stdio(0);
	for (int i = 2; i < M; ++i) {
		if (cool[i]) continue;
		prime.pb(i);
		for (int j = i * i; j < M; j += i) {
			cool[j] = true;
		}
	}
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		for (auto j : prime) {
			if (j * j > a[i]) break;
			int cnt = 0;
			while (a[i] % j == 0) {
				++cnt;
				a[i] /= j;
			}
			if (cnt & 1) p[i].pb(j);
		}
		if (a[i] != 1) p[i].pb(a[i]);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 15; ++j) {
			L[i][j] = -1e9;
		}
		//cout << p[i] << endl;
		for (int j = 0; j < (1 << p[i].size()); ++j) {
			int s = p[i].size();
			int hash = 1;
			for (int q = 0; q < p[i].size(); ++q) {
				if ((j >> q) & 1) {
					hash *= p[i][q];
					--s;
				}
			}
			for (int q = 0; q <= 7; ++q) {
				if (who[q].count(hash)) {
					chkmax(L[i][q + s], who[q][hash]);
				}
			}
			who[s][hash] = i;
		}
	}
	for (int i = 1; i < N; ++i) {
		g[i] = g[i >> 1] + 1; 
	}
	ask.resize(m);
	ans.resize(m, 11);
	cin >> ask;
	for (int w = 0; w < 11; ++w) {
		for (int i = 0; i < n; ++i) t[0][i] = L[i][w];
		for (int j = 0; (1 << j) < n; ++j) {
			for (int q = 0; q + (1 << j) < n; ++q) {
				t[j + 1][q] = max(t[j][q], t[j][q + (1 << j)]);
			}
		}
		for (int i = 0; i < m; ++i) {
			if (get(ask[i].x, ask[i].y) >= ask[i].x) {
				chkmin(ans[i], w);
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		cout << ans[i] << '\n';
	}
}