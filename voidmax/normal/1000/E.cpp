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
         
typedef pair<int, int> point;
 
const int MAXN = 3e5 + 1;

int n, m;
vector<int> edge[MAXN];
int up[MAXN], h[MAXN];
bool used[MAXN];

set<pair<int, int>> cool;

void dfs(int i, int p = -1) {
	up[i] = h[i];
	used[i] = true;
	for (auto j : edge[i]) {
		if (j == p) continue;
		if (used[j]) {
			chkmin(up[i], h[j]);
		} else {
			h[j] = h[i] + 1;
			dfs(j, i);
			chkmin(up[i], up[j]);
		}
	}
	if (up[i] == h[i] && h[i]) {
		cool.insert({i, p});
		cool.insert({p, i});
	}
}

int clr[MAXN];

void dfs_clr(int i, int c) {
	if (clr[i]) return;
	clr[i] = c;
	for (auto j : edge[i]) {
		if (cool.count({i, j})) {
			continue;
		}
		dfs_clr(j, c);
	}
}

int ans;
set<int> ne[MAXN];

int find_max_dist(int i, int p = -1) {
	vector<int> dist;
	dist.pb(0);
	dist.pb(0);
	for (auto j : ne[i]) {
		if (j == p) continue;
		dist.pb(find_max_dist(j, i) + 1);
	}
	sort(dist.rbegin(), dist.rend());
	chkmax(ans, dist[0] + dist[1]);
	return dist[0];
}

int main() {
    ios::sync_with_stdio(false);
    srand(time(0));
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
    	int a, b;
    	cin >> a >> b;
    	edge[a].pb(b);
    	edge[b].pb(a);
    }
    dfs(1);
    for (int i = 1; i <= n; ++i) {
    	dfs_clr(i, i);
    }
    for (auto e : cool) {
    	ne[clr[e.x]].insert(clr[e.y]);
    	ne[clr[e.y]].insert(clr[e.x]);
    }
    find_max_dist(1);
    cout << ans << '\n';
}