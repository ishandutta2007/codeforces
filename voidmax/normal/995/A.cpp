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
 
int n, k;
int a[5][200];

point nxt(point a) {
	if (a.x == 2) {
		if (a.y == n) {
			return {3, n};
		} 
		return {2, a.y + 1};
	} 
	if (a.y == 1) {
		return {2, 1};
	}
	return {3, a.y - 1};
}

int main() {
    ios::sync_with_stdio(false);
    srand(time(0));
    cin >> n >> k;
   	for (int i = 1; i <= 4; ++i) {
   		for (int j = 1; j <= n; ++j) {
   			cin >> a[i][j];
   		}
   	}
   	vector<pair<int, point>> ans;
   	while (k) {
   		// cout << "step" << ' ' << k << endl;
   		// for (int i = 1; i <= 4; ++i) {
   		// 	for (int j = 1; j <= n; ++j) {
   		// 		cout << a[i][j] << ' ';
   		// 	}
   		// 	cout << endl;
   		// }
   		// cout << endl;
   		bool found = false;
   		for (int j = 1; j <= n; ++j) {
   			if (a[2][j] == a[1][j] && a[1][j]) {
   				ans.pb({a[2][j], {1, j}});
   				found = true;
   				a[1][j] = a[2][j] = 0;
   				--k;
   			}
   			if (a[3][j] == a[4][j] && a[4][j]) {
   				ans.pb({a[3][j], {4, j}});
   				found = true;
   				a[4][j] = a[3][j] = 0;
   				--k;
   			}
   		} 
   		if (found) continue;
   		if (k == n * 2) {
   			cout << -1 << endl;
   			return 0;
   		}
   		vector<pair<int, point>> dir;
   		for (int i = 1; i <= n; ++i) {
   			if (a[2][i]) {
   				dir.pb({a[2][i], nxt({2, i})});
   				a[2][i] = 0;
   				break;
   			} 
   		}
   		if (dir.size() == 0) {
   			for (int i = n; i >= 1; --i) {
	   			if (a[3][i]) {
	   				dir.pb({a[3][i], nxt({3, i})});
	   				a[3][i] = 0;
	   				break;
	   			} 
	   		}
   		}
   		assert(dir.size());
   		point lst = dir.back().y;
   		//cout << "?" << lst << endl;
   		while (a[lst.x][lst.y]) {
   			//cout << lst << endl;
   			dir.pb({a[lst.x][lst.y], nxt(lst)});
   			a[lst.x][lst.y] = 0;
   			lst = nxt(lst);
   			//cout << lst << endl;
   		}
   		reverse(dir.begin(), dir.end());
   		for (auto i : dir) {
   			a[i.y.x][i.y.y] = i.x;
   			//cout << i.y.x << ':' << i.y.y  << endl;
   			ans.pb(i);
   		} 
   		// for (int i = 1; i <= 4; ++i) {
   		// 	for (int j = 1; j <= n; ++j) {
   		// 		cout << a[i][j] << ' ';
   		// 	}
   		// 	cout << endl;
   		// }

   	}
   	cout << ans.size() << '\n';
   	for (auto i : ans) {
   		cout << i << '\n';
   	}
}