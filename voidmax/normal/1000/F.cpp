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
 
const int N = 1 << 19;

struct seg_tree {
	pair<int, int> t[N * 2 + 1];

	seg_tree() {
		for (int i = 0; i < N; ++i) {
			t[i + N].y = i;
		}
		for (int i = N; i--;) {
			t[i].y = t[i >> 1].y;
		}
	}

	void chg(int i, int d) {
		i += N;
		t[i].x = d;
		while (i > 1) {
			i >>= 1;
			t[i] = min(t[i * 2], t[i * 2 + 1]);
		}
	}

	pair<int, int> get(int i, int L, int R, int Ln, int Rn) {
		if (Ln <= L && R <= Rn) {
			return t[i];
		}
		if (Rn <= L || R <= Ln) {
			return {1e9, -1};
		}
		int M = (L + R) >> 1;
		return min(get(i * 2, L, M, Ln, Rn), get(i * 2 + 1, M, R, Ln, Rn));
	}
} box;

int n, m;
int a[N + 1];
int lst[N + 1];
int L[N + 1], R[N + 1];
vector<int> who[N + 1];
int ans[N + 1];

int main() {
    ios::sync_with_stdio(false);
    srand(time(0));
    cin >> n;
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
    	cin >> L[i] >> R[i];
    	who[R[i]].pb(i);
    }
    for (int i = 1; i <= n; ++i) {
    	box.chg(lst[a[i]], 1e9);
    	box.chg(i, lst[a[i]]);
    	lst[a[i]] = i;
    	for (auto j : who[i]) {
    		auto v = box.get(1, 0, N, L[j], R[j] + 1);
    		if (v.x < L[j]) {
    			ans[j] = a[v.y];
    		}
    	}
    }
    for (int i = 0; i < m; ++i) {
    	cout << ans[i] << '\n';
    }
}