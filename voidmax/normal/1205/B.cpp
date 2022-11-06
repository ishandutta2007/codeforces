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

const int N = 1e6 + 5;

int n;
set<pair<int, int>> edge;
vector<int> who[62];
long long a[N];

vector<pair<int, int>> que;

vector<int> re[N];

int dfs(int i, int f, int p = -1) {
	if (i == f) return 0;
	for (int j : re[i]) {
		if (j == p) continue;
		int ans = dfs(j, f, i);
		if (ans != -1) return ans + 1;
	}
	return -1;
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    double st = clock();
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    	if (a[i] == 0) {
    		--i;
    		--n;
    	} 
    }
    if (n == 0) {
    	cout << -1 << '\n';
    	return 0;
    }
    for (int t = 0; t < 60; ++t) {
    	for (int i = 0; i < n; ++i) {
    		if ((a[i] >> t) & 1) {
    			who[t].pb(i);
    		}
    	}
    	if (who[t].size() >= 3) {
    		cout << 3 << '\n';
    		return 0;
    	}
    	for (int i : who[t]) {
    		for (int j : who[t]) {
    			if (i >= j) continue;
    			edge.insert({i, j});
    		}
    	}
    } 
    for (auto i : edge) que.pb(i);
    int ans = 1e9;
	while ((clock() - st) / CLOCKS_PER_SEC < 0.9) {
		random_shuffle(que.begin(), que.end());
		for (auto i : que) {
			re[i.x].clear();
			re[i.y].clear();
		}
		for (auto i : que) {
			int rep = dfs(i.x, i.y) + 1;
			if (rep) {
				chkmin(ans, rep);
			} else {
				re[i.x].pb(i.y);
				re[i.y].pb(i.x);
			} 
		}
	}
	if (ans > n) ans = -1;
	cout << ans << '\n';
}