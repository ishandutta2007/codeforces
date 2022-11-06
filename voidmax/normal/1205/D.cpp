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

const int N = 1e3 + 5;

int n;
vector<int> edge[N];

int s[N];
vector<int> ord;

int dfs(int i, int p = -1) {
	s[i] = 1;
	for (int j : edge[i]) {
		if (j == p) continue;
		s[i] += dfs(j, i);
	}
	ord.pb(i);
	return s[i];
}

int c;
set<int> que;
long long w[N];

void dfs_clr(int i, int p = -1) {
	w[i] = *que.begin();
	que.erase(que.begin());
	for (auto j : edge[i]) {
		if (j == p) continue;
		dfs_clr(j, i);
	}
}	

void solve() {
	dfs(1);
	for (int i : ord) {
		if (s[i] * 2 >= n) {
			c = i;
			break;
		}
	} 
	vector<pair<int, int>> ord;
	for (int i : edge[c]) {
		ord.pb({dfs(i, c), i});
	}
	sort(ord.rbegin(), ord.rend());
	vector<int> L, R;
	int wL = 0, wR = 0;
	for (auto i : ord) {
		if (wL > wR) {
			swap(wL, wR), swap(L, R);
		}
		wL += i.x;
		L.pb(i.y);
	}
	if ((wL + 1) * wR < wL * (wR + 1)) {
		swap(wL, wR), swap(L, R);
	}
	assert((wL + 1) * wR >= 2 * n * n / 9);
	w[c] = 0;
	for (int i = 1; i < wL + 1; ++i) que.insert(i * wR);
	for (auto i : L) dfs_clr(i, c);
	for (int i = 0; i < wR; ++i) que.insert(i + 1);
	for (auto i : R) dfs_clr(i, c);
}

vector<pair<int, int>> rep;

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    cin >> n;
    for (int i = 1; i < n; ++i) {
    	int a, b;
    	cin >> a >> b;
    	edge[a].pb(b);
    	edge[b].pb(a);
    	rep.pb({a, b});
    }
    solve();
    for (auto i : rep) {
    	cout << i.x << ' ' << i.y << ' ' << abs(w[i.x] - w[i.y]) << '\n';
    }
}