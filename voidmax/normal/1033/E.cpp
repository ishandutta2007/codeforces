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
 
typedef long long base;       
typedef pair<int, int> point;

const int MAXN = 601;

int n;

vector<int> edge[MAXN];

map<vector<int>, int> repx;

int ask(vector<int> arr, int delta = 0) {
	if (arr.size() < 2) return -delta;
	sort(arr.begin(), arr.end());
	int cnt = 0;
	if (!repx.count(arr)) {
		if (repx.size() == 2e4) {
			assert(false);
		}
		cout << "? " << arr.size() << ' ' << arr << endl;
		cin >> cnt;
		repx[arr] = cnt;
	} else {
		cnt = repx[arr];
	}
	return cnt - delta;
}

vector<int> operator + (vector<int> a, vector<int> b) {
	for (auto i : b) {
		a.pb(i);
	}
	return a;
}

int L = 0;
bool alive[2001];
int w[2001];
pair<vector<int>, vector<int>> res[2000];


bool find_edge(vector<int> a, vector<int> b, bool need_to_find = true) {
	if (a.size() == 0 || b.size() == 0)
		return false;
	vector<int> c = a + b;
	int ans = ask(c);
	if (!ans) {
		return false;
	} 
	if (!need_to_find) return true;
	if (a.size() < b.size()) {
		swap(a, b);
	}
	if (a.size() == 1) {
		edge[a[0]].pb(b[0]);
		// cout << "			" << a[0] << ' ' << b[0] << endl;
		edge[b[0]].pb(a[0]);
		return true;
	} else {
		vector<int> A[2];
		for (int i = 0; i < a.size(); ++i) {
			A[i & 1].pb(a[i]);
		}
		if (find_edge(A[1], b, need_to_find)) {
			return true;
		}
		return find_edge(A[0], b, need_to_find);
	}
}

int rep[2001];
int used[2001];

vector<int> bad_ans;

int dfs(int i, int cur = 0) {
	if (used[i] && rep[i] != cur) {
		bad_ans.pb(i);
		return 1;
	}
	if (used[i]) return 0;
	used[i] = true;
	rep[i] = cur;
	for (int j : edge[i]) {
		int f = dfs(j, !cur);
		if (f == 2) {
			return 2;
		}
		if (f == 1) {
			if (bad_ans[0] == i) {
				return 2;
			}
			bad_ans.pb(i);
			return 1;
		}
	}
	return 0;
}

void find_error() {
	for (int i = 1; i <= n; ++i) {
		if (dfs(i)) {
			cout << "N " << bad_ans.size() << endl;
			cout << bad_ans << endl;
			exit(0);
		}
	}
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    // read("input");
    cin >> n;
    for (int t = 1; t <= n; ++t) {
    	alive[L] = true;
    	res[L].x = {t};
    	++L;
    	while (true) {
    		vector<int> who;
    		vector<int> id;
    		int delta = 0;
    		for (int i = 0; i < L; ++i) {
    			if (alive[i]) {
    				delta += w[i];
    				id.pb(i);
    				for (int j : res[i].x) {
    					who.pb(j);
    				}
    				for (int j : res[i].y) {
    					who.pb(j);
    				}
    			}
    		}
    		if (id.size() == 1) break;
    		int ans = ask(who, delta);
    		if (ans == 0) break;
    		int Ln = 0, Rn = (int)id.size() - 1; 
    		while (Rn - Ln > 1) {
    			int M = (Ln + Rn) >> 1;
    			who.clear();
    			delta = 0;
    			for (int i = M; i < id.size(); ++i) {
    				delta += w[id[i]];
    				for (int j : res[id[i]].x) {
    					who.pb(j);
    				}
    				for (int j : res[id[i]].y) {
    					who.pb(j);
    				}	
    			}
    			ans = ask(who, delta);
    			if (ans) {
    				Ln = M;
    			} else {
    				Rn = M;
    			}
    		}
    		int A = id[Ln], B = L - 1;
    		bool ans1 = find_edge(res[A].x, res[B].x, false);
    		bool ans2 = find_edge(res[A].x, res[B].y, false);
    		if (ans1 && ans2) {
    			find_edge(res[A].x, res[B].x, true);
    			find_edge(res[A].x, res[B].y, true);
    			find_error();
    			return 0;
    		}
    		bool ans3 = find_edge(res[A].y, res[B].x, false);
    		bool ans4 = find_edge(res[A].y, res[B].y, false);
    		if ((ans3 && ans4) || (ans3 && ans1) || (ans4 && ans2)) {
    			find_edge(res[A].x, res[B].x, true);
    			find_edge(res[A].x, res[B].y, true);
    			find_edge(res[A].y, res[B].x, true);
    			find_edge(res[A].y, res[B].y, true);
    			find_error();
    			return 0;
    		}
    		if (ans1 || ans4) {
    			swap(res[B].x, res[B].y);
    		}
    		// cout << ans1 << ' ' << ans2 << ' ' << ans3 << ' ' << ans4 << endl;
    		if (!find_edge(res[B].x, res[A].y, true)) {
    			// cout << res[B].x << ':' << res[B].y << ':' << endl;
    			// cout << res[A].x << ':' << res[A].y << ':' << endl;
    			find_edge(res[B].y, res[A].x, true);
    			// cout << endl;
    		}
    		alive[A] = false;
    		for (int j : res[A].x) {
				res[B].x.pb(j);
			}
			res[A].x.clear();
			for (int j : res[A].y) {
				res[B].y.pb(j);
			}
			res[A].y.clear();
			w[B] = ask(res[B].x + res[B].y);
    	}	
    }
    for (int i = 1; i <= n; ++i) {
    	if (!used[i]) dfs(i);
    }
    vector<int> res[2];
    for (int i = 1; i <= n; ++i) {
    	res[rep[i]].pb(i);
    }
    cout << "Y " << res[0].size() << endl;
    cout << res[0] << endl;
}