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

const int N = 1 << 18;

struct seg_tree {
	long long t[N * 2 + 1];
	long long mod[N * 2 + 1];

	void push(int i) {
		t[i] += mod[i];
		if (i < N) {
			mod[i * 2] += mod[i];
			mod[i * 2 + 1] += mod[i];
		}
		mod[i] = 0;
	}

	void chg(int i, int L, int R, int Ln, int Rn, int d) {
		if (Ln <= L && R <= Rn) {
			mod[i] += d;
			push(i);
			return;
		}
		push(i);
		if (Rn <= L || R <= Ln) {
			return;
		}
		int M = (L + R) >> 1;
		chg(i << 1, L, M, Ln, Rn, d);
		chg((i << 1) + 1, M, R, Ln, Rn, d);
		t[i] = max(t[i << 1], t[(i << 1) + 1]);
	}

	int get(int i, int L, int R) {
		push(i); 
		if (t[i] < 0) return -1;
		if (R - L == 1) {
			if (t[i] == 0) return R;
			return -1;
		}
		int M = (L + R) >> 1;
		int ans = get(i << 1, L, M);
		if (ans == -1) {
			return get((i << 1) + 1, M, R);
		}
		return ans;
	}
} box;

int n, m;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		box.chg(1, 0, n, i, i + 1, a[i]);
		box.chg(1, 0, n, i + 1, n, -a[i]);
	}
	for (int i = 0; i < m; ++i) {
		int id, v;
		cin >> id >> v;
		--id;
		box.chg(1, 0, n, id, id + 1, v - a[id]);
		box.chg(1, 0, n, id + 1, n, a[id] - v);
		a[id] = v;
		cout << box.get(1, 0, n) << '\n';
	}
}