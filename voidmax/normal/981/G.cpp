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
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
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

const int p = 998244353;
const int rev2 = -1;    
const int N = 1 << 18;

void sum(long long &a, long long b) {
	a += b;
	if (a >= p) 
		a -= p;
}

void mul(long long &a, long long b) {
	a *= b;
	a %= p;
}

int sz[N * 2];

struct seg_tree {
	long long mod[N * 2][2];	
	long long v[N * 2];

	seg_tree() {
		for (int i = 0; i < N; ++i) {
			sz[N + i] = 1; 
		}
		for (int i = N; i--;) {
			sz[i] = sz[i * 2] * 2;
		} 
		for (int i = 0; i < N * 2; ++i) {
			mod[i][0] = 1;
		}
	}

	void push(int i) {
		mul(v[i], mod[i][0]);
		sum(v[i], (mod[i][1] * sz[i]) % p);
		if (i < N) {
			mul(mod[i<<1][0], mod[i][0]);
			mul(mod[i<<1][1], mod[i][0]);
			sum(mod[i<<1][1], mod[i][1]);
			mul(mod[(i<<1)+1][0], mod[i][0]);
			mul(mod[(i<<1)+1][1], mod[i][0]);
			sum(mod[(i<<1)+1][1], mod[i][1]);
		}
		mod[i][0] = 1;
		mod[i][1] = 0;
	}

	long long add(int i, int L, int R, int Ln, int Rn) {
		// if (L == 0 && R == N) {
		// 	cout << "+ " << Ln << ' ' << Rn - 1 << endl;
		// }
		if (Ln <= L && R <= Rn) {
			sum(mod[i][1], 1);
			push(i);
			return v[i];
		}
		push(i);
		if (Rn <= L || R <= Ln) {
			return v[i];
		}
		int M = (L + R) >> 1;
		v[i] = add(i * 2, L, M, Ln, Rn);
		sum(v[i], add(i * 2 + 1, M, R, Ln, Rn));
		return v[i];
	}

	long long chg(int i, int L, int R, int Ln, int Rn) {
		// if (L == 0 && R == N) {
		// 	cout << "* " << Ln << ' ' << Rn - 1 << endl;
		// }
		if (Ln <= L && R <= Rn) {
			mul(mod[i][0], 2);
			sum(mod[i][1], mod[i][1]);
			push(i);
			return v[i];
		}
		push(i);
		if (Rn <= L || R <= Ln) {
			return v[i];
		}
		int M = (L + R) >> 1;
		v[i] = chg(i * 2, L, M, Ln, Rn);
		sum(v[i], chg(i * 2 + 1, M, R, Ln, Rn));
		return v[i];
	}

	long long get(int i, int L, int R, int Ln, int Rn) {
		push(i);
		if (Ln <= L && R <= Rn) {
			return v[i];
		}
		if (Rn <= L || R <= Ln) {
			return 0;
		}
		int M = (L + R) >> 1;
		long long ans = get(i * 2, L, M, Ln, Rn);
		sum(ans, get(i * 2 + 1, M, R, Ln, Rn));
		return ans;
	}
} box;

typedef pair<int, int> point;

int n, m;
set<point> arr[N];

vector<point> get(int clr, int L, int R) {
	vector<point> ans;
	auto it = arr[clr].lower_bound({L, -1});
	if (it != arr[clr].begin()) {
		--it;
		auto u = *it;
		if (max(L, u.x) <= min(R, u.y)) {
			ans.pb(u);
			arr[clr].erase(it);
		}
	}
	while (true) {
		auto it = arr[clr].lower_bound({L, -1});
		if (it == arr[clr].end()) break;
		auto u = *it;
		if (max(L, u.x) <= min(R, u.y)) {
			ans.pb(u);
			arr[clr].erase(it);
		} else {
			break;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	//freopen("input.in", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int t, L, R, clr;
		cin >> t >> L >> R;
		++R;
		if (t == 1) {
			//cout << endl;
			cin >> clr;
			vector<point> que = get(clr, L, R);
			int lst = L;
			for (auto i : que) {
				auto u = i;
				chkmax(u.x, L);
				chkmin(u.y, R);
				if (lst != u.x) box.add(1, 0, N, lst, u.x);
				if (u.x != u.y) box.chg(1, 0, N, u.x, u.y);
				lst = u.y;
			}
			if (lst != R) box.add(1, 0, N, lst, R);
			if (que.size()) {
				chkmin(L, que[0].x);
				chkmax(R, que.back().y);
			}
			arr[clr].insert({L, R});
		} else {
			cout << box.get(1, 0, N, L, R) << '\n';
		}
		//cout << "?" << box.v[1] << endl;
	}
}