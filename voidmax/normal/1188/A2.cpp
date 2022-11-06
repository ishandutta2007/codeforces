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

int n;
vector<int> w;
pair<int, int> p[N];
vector<pair<int, int>> edge[N];

map<pair<int, int>, int> ans;

void add(int a, int b, int c) {
	if (a == b) return;
	if (a > b) swap(a, b);
	ans[{a, b}] += c;
}

void dfs(int i, int p = -1) {
	for (auto e : edge[i]) {
		if (e.x == p) continue;
		::p[e.x] = {i, e.y};
		dfs(e.x, i);
	}
}

int get_node(int a, int b) {
	for (auto e : edge[a]) {
		if (e.x == b) continue;
		return get_node(e.x, a);
	}
	return a;
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    cin >> n;
    for (int i = 0; i + 1 < n; ++i) {
    	int a, b, c;
    	cin >> a >> b >> c;
    	edge[a].pb({b, i});
    	edge[b].pb({a, i});
   		w.pb(c);
    }
    int root = -1;
    for (int i = 1; i <= n; ++i) {
    	if (edge[i].size() >= 3) {
    		root = i;
    	}
    }
    if (root == -1) {
   		vector<int> who;
   		for (int i = 1; i <= n; ++i) {
   			if (edge[i].size() == 1) {
   				who.pb(i);
   			}
   		}
   		sort(w.begin(), w.end());
   		if (w[0] != w.back()) {
   			cout << "NO\n";
   			return 0;
   		}
   		cout << "YES\n";
   		cout << 1 << '\n';
   		cout << who[0] << ' ' << who[1] << ' ' << w[0] << '\n';
   		return 0;
    }
    dfs(root);
    for (int i = 1; i <= n; ++i) {
    	if (edge[i].size() != 1) continue;
    	vector<int> nodes;
    	vector<int> costs;
    	vector<int> edges;
    	nodes.pb(i);
    	while (nodes.back() != root) {
    		costs.pb(w[p[nodes.back()].y]);
    		edges.pb(p[nodes.back()].y);
    		nodes.pb(p[nodes.back()].x);
    	}
    	costs.pb(0);
    	for (int j = 0; j + 1 < costs.size(); ++j) {
    		if (costs[j] != costs[j + 1]) {
    			if (edge[nodes[j + 1]].size() == 2) {
    				cout << "NO\n";
    				return 0;
    			}
    			vector<int> who;
    			for (auto e : edge[nodes[j + 1]]) {
    				if (e.x == nodes[j]) continue;
    				who.pb(get_node(e.x, nodes[j + 1]));
    				if (who.size() == 2) break;
    			}
    			assert(who.size() == 2);
    			int A = i;
    			int B = who[0];
    			int C = who[1];
    			int d = costs[j + 1] - costs[j];
    			add(A, B, d / 2);
    			add(A, C, d / 2);
    			add(B, C, -d / 2);
    			for (int q = 0; q <= j; ++q) {
    				w[edges[q]] += d;
    				costs[q] += d;
    			}
    		}
    	}
    }
    cout << "YES\n";
    cout << ans.size() << '\n';
    for (auto i : ans) {
    	cout << i.x.x << ' ' << i.x.y << ' ' << -i.y << '\n';
    }
}