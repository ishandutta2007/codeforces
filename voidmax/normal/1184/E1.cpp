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

const int N = 2e5 + 5;

int n, m;
int dsu[N];
vector<pair<int, int>> edge[N];
vector<pair<int, pair<int, int>>> edges;

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

void dfs(int i, int t, int p = -1, int maxe = 0) {
	// cout << i << ' ' << t << endl;
	if (i == t) {
		cout << maxe << '\n';
		exit(0);
	}
	for (auto e : edge[i]) {
		if (e.x == p) continue;	
		// cout << e << endl;
		dfs(e.x, t, i, max(maxe, e.y));
	}
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    cin >> n >> m;
    edges.resize(m);
    for (int i = 0; i < m; ++i) {
    	cin >> edges[i].y.x >> edges[i].y.y >> edges[i].x;
    }
    auto v = edges[0];
    sort(edges.begin(), edges.end());
    bool was = false;
    for (int i = 0; i <= n; ++i) dsu[i] = i;
    for (auto i : edges) {
    	if (v == i) {
    		if (!was) {
    			was = true;
    			continue;
    		}
    	}
    	// cout << i << ' ' << get(i.y.x) << ' ' << get(i.y.y) << endl;
    	if (merge(i.y.x, i.y.y)) {
    		// cout << i << endl;
    		edge[i.y.x].pb({i.y.y, i.x});
    		edge[i.y.y].pb({i.y.x, i.x});
    	}
    }
    dfs(v.y.x, v.y.y);
    cout << 1000000000 << '\n';
}