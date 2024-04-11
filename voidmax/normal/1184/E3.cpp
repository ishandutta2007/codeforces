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
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("unroll-loops")    
#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define len(a) int(a.size())
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
typedef complex<double> comp;
 
const int N = 1e5 + 5;
 
int n, m;
int dsu[N], h[N];
vector<pair<int, int>> edge[N];
vector<pair<int, int>> bedge[N];
vector<pair<int, pair<int, int>>> edges, v;
set<pair<int, int>> used;
map<pair<int, int>, int> ans;
 
int get(int i) {
	return i == dsu[i] ? i : dsu[i] = get(dsu[i]);
}
 
bool merge(int i, int j) {
	i = get(i);
	j = get(j);
	if (i == j) return false;
	dsu[i] = j;
	return true;
}
 
const int LOG = 18;
 
int t;
int tin[N], tout[N];
pair<int, int> up[LOG][N]; 
int bad[LOG][N];
 
void dfs(int i, int p = -1) {
	tin[i] = t++;
	for (auto j : edge[i]) {
		if (j.x == p) continue;
		up[0][j.x] = {i, j.y};
		h[j.x] = h[i] + 1;
		dfs(j.x, i);
	}
	tout[i] = t++;
}
 
bool is_parent(int a, int b) {
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}
 
int lca(int a, int b, int v) {
	int ans = 0;
	for (int t = 0; t < 2; ++t) {
		if (tin[a] > tin[b]) swap(a, b);
		if (!is_parent(b, a)) {
			for (int t = LOG; t--;) {
				int c = up[t][b].x;
				if (!is_parent(c, a)) {
					chkmax(ans, up[t][b].y);
					chkmin(bad[t][b], v);
					b = c;
				}
			}
			chkmax(ans, up[0][b].y);
			chkmin(bad[0][b], v);
			b = up[0][b].x;
		}
		// cout << b << ' '  << tin[b] << ' ' << tout[b] << endl;
		// cout << a << ' '  << tin[a] << ' ' << tout[a] << endl;
		assert(is_parent(b, a));
	}
	// cout << a << ' ' << b << endl;
	return ans;
}
 
int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    cin >> n >> m;
    edges.resize(m);
    for (int i = 0; i < m; ++i) {
    	cin >> edges[i].y.x >> edges[i].y.y >> edges[i].x;
    }
    v = edges;
    sort(edges.begin(), edges.end());
    bool was = false;
    for (int i = 0; i <= n; ++i) dsu[i] = i;
    for (auto i : edges) {
    	if (merge(i.y.x, i.y.y)) {
    		used.insert(i.y);
    		edge[i.y.x].pb({i.y.y, i.x});
    		edge[i.y.y].pb({i.y.x, i.x});
    	} else {
    		bedge[i.y.x].pb({i.y.y, i.x});
    		bedge[i.y.y].pb({i.y.x, i.x});
    	}
    }
    up[0][1] = {1, 0};
    dfs(1);
    for (int t = 0; t < LOG; ++t) {
    	for (int i = 1; i <= n; ++i) {
    		bad[t][i] = 1e9;
    	}
    }
    for (int t = 0; t + 1 < LOG; ++t) {
    	for (int i = 1; i <= n; ++i) {
    		up[t + 1][i] = {up[t][up[t][i].x].x, max(up[t][i].y, up[t][up[t][i].x].y)};
    	}
    }
    for (auto i : v) {
    	if (used.count(i.y)) {
    		continue;
    	}
    	ans[i.y] = lca(i.y.x, i.y.y, i.x);
    }
    for (int t = LOG - 1; t--;) {
    	for (int i = 1; i <= n; ++i) {
    		int j = up[t][i].x;
    		chkmin(bad[t][i], bad[t + 1][i]);
    		chkmin(bad[t][j], bad[t + 1][i]);
    	}
    }
    for (int i = 2; i <= n; ++i) {
    	int j = up[0][i].x;
    	ans[{i, j}] = ans[{j, i}] = bad[0][i];
    }
    for (auto i : v) {
    	cout << ans[i.y] << '\n';
    }
}