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

const int N = 1e6 + 1;

int n;
int val[N];
int t[N];
map<string, int> tp = {{"IN", 0}, {"AND", 1}, {"OR", 2}, {"XOR", 3}, {"NOT", 4}};
vector<int> edge[N];

void add(vector<int> &a, vector<int> &b) {
	if (a.size() < b.size()) {
		swap(a, b);
	}
	for (auto i : b) {
		a.pb(i);
	}
}

bool dfs(int i, vector<int> &L, vector<int> &R) {
	if (t[i] == 0) {
		if (edge[i][0]) {
			L.pb(i);
		} else {
			R.pb(i);
		}
		return edge[i][0];
	}
	if (1 <= t[i] && t[i] <= 3) {
		bool ans1, ans2;
		vector<int> L1, L2, R1, R2;
		ans1 = dfs(edge[i][0], L1, R1);
		ans2 = dfs(edge[i][1], L2, R2);
		if (t[i] == 1) {
			add(L, L1);
			add(L, L2);
			if (ans1 == 0) add(L, R2);
			else 		   add(R, R2);
			if (ans2 == 0) add(L, R1);
			else 		   add(R, R1);
			return ans1 & ans2;
		} else if (t[i] == 2) {
			add(R, R1);
			add(R, R2);
			if (ans1 == 0) add(L, L2);
			else 		   add(R, L2);
			if (ans2 == 0) add(L, L1);
			else 		   add(R, L1);
			return ans1 | ans2;
		} else {
			if (ans1 == 0) add(L, L2), add(R, R2);
			else 		   add(R, L2), add(L, R2);
			if (ans2 == 0) add(L, L1), add(R, R1);
			else 		   add(R, L1), add(L, R1);
			return ans1 ^ ans2;
		} 
	} else {
		return !dfs(edge[i][0], R, L);
	}
}

bool ans[N];

int main() {
	ios::sync_with_stdio(0);
	cin >> n; 
	for (int i = 1; i <= n; ++i) {
		string res;
		cin >> res;
		if (res == "AND" || res == "OR" || res == "XOR") {
			int a, b;
			cin >> a >> b;
			edge[i] = {a, b};
		} else {
			int a;
			cin >> a;
			edge[i].pb(a);
		}
		t[i] = tp[res];
	}
	vector<int> L, R;
	dfs(1, L, R);
	for (auto i : R) {
		ans[i] = true;
	}
	for (int i = 1; i <= n; ++i) {
		if (t[i] == 0) cout << ans[i];
	}
	cout << '\n';
}