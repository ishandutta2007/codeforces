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
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((string(FILENAME) + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((string(FILENAME) + ".out").c_str(), "w", stdout)
#ifdef ON_PC
#define _getchar_nolock getchar_unlocked
#endif
using namespace std;
	  //g++ -o file --std=c++11 -D ON_PC
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
	   
typedef pair<int, int> point;

int ri() {
	int v = 0;
	char c = _getchar_nolock();
	while ('0' <= c && c <= '9') {
		v = (v << 3) + (v << 1) + c - '0';
		c = _getchar_nolock();
	}
	return v;
}

const int MAXN = 1e5 + 1;

int n, m, k, s;
int clr[MAXN];
int ans[MAXN], sz[MAXN];
vector<int> edge[MAXN];
int dist[MAXN];
vector<int> f[MAXN];

void bfs(int c) {
	queue<int> que;
	for (int i = 0; i < n; ++i) {
		dist[i] = 1e9;
		if (clr[i] == c) {
			dist[i] = 0;
			que.push(i);
		}
	}
	while (que.size()) {
		auto u = que.front();
		f[dist[u]].pb(u);
		que.pop();
		for (auto v : edge[u]) {
			if (dist[v] == 1e9) {
				dist[v] = dist[u] + 1;
				que.push(v); 
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	n = ri(), m = ri(), k = ri(), s = ri();
	for (int i = 0; i < n; ++i) {
		clr[i] = ri() - 1;
	}
	for (int i = 0; i < m; ++i) {
		int a = ri() - 1, b = ri() - 1;
		edge[a].pb(b);
		edge[b].pb(a);
	}
	for (int i = 0; i < k; ++i) {
		bfs(i);
	}
	for (int i = 0; i <= m; ++i) {
		for (auto j : f[i]) {
			if (sz[j] != s) {
				++sz[j];
				ans[j] += i;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}