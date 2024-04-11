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

int n;
vector<int> dev[100001];

long long ans = 0;

int gcd(int a, int b) {
	return a ? gcd(b % a, a) : b;
}

int my_solve(int a, int b, int c) {
	set<vector<int>> ans;
	for (int i : dev[a]) {
		for (int j : dev[b]) {
			for (int q : dev[c]) {
				vector<int> res = {i, j, q};
				sort(res.begin(), res.end());
				ans.insert(res);
			}
		}
	}
	return ans.size();
}

vector<vector<int>> cool[4];

int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	int d = 0;
	for (int i = 1; i <= 1e5; ++i) {
		for (int j = i; j <= 1e5; j += i) {
			dev[j].pb(i);
		}
		chkmax(d, dev[i].size());
	}
	for (int a = 0; a < 8; ++a) {
		for (int b = a; b < 8; ++b) {
			for (int c = b; c < 8; ++c) {
				bool can = false;
				for (int i = 0; i < 3; ++i) {
					for (int j = 0; j < 3; ++j) {
						if (i == j) continue;
						int q = 3 - i - j;
						if (((a >> i) & 1) && ((b >> j) & 1) && ((c >> q) & 1)) {
							can = true;
						}
					}
				}
				if (can) {
					if (a == b && b == c) {
						cool[0].pb({a, b, c});
					} else if (a == b) {
						cool[1].pb({a, b, c});
					} else if (b == c) {
						cool[2].pb({a, b, c});
					} else {
						cool[3].pb({a, b, c});
					}
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		int A[3];
		cin >> A[0] >> A[1] >> A[2];
		//cout << A[0] << ' ' << A[1] << ' ' << A[2] << endl;
		vector<int> cnt(8);
		cnt[1 + 2 + 4] = dev[gcd(gcd(A[0], A[1]), A[2])].size();
		cnt[1 + 2 + 0] = dev[gcd(A[0], A[1])].size() - cnt[1 + 2 + 4];
		cnt[1 + 0 + 4] = dev[gcd(A[0], A[2])].size() - cnt[1 + 2 + 4];
		cnt[0 + 2 + 4] = dev[gcd(A[1], A[2])].size() - cnt[1 + 2 + 4];
		cnt[1 + 0 + 0] = dev[A[0]].size() - cnt[1 + 2 + 0] - cnt[1 + 0 + 4] - cnt[1 + 2 + 4];
		cnt[0 + 2 + 0] = dev[A[1]].size() - cnt[1 + 2 + 0] - cnt[0 + 2 + 4] - cnt[1 + 2 + 4];
		cnt[0 + 0 + 4] = dev[A[2]].size() - cnt[1 + 0 + 4] - cnt[0 + 2 + 4] - cnt[1 + 2 + 4];
		//for (int i = 0; i < 8; ++i) cout << cnt[i] << ' '; cout << endl;
		int ans = 0;
		for (auto j : cool[0]) {
			ans += cnt[j[0]] * (cnt[j[0]] + 1) * (cnt[j[0]] + 2) / 6;
		}
		for (auto j : cool[1]) {
			ans += cnt[j[0]] * (cnt[j[0]] + 1) / 2 * cnt[j[2]];
		}
		for (auto j : cool[2]) {
			ans += cnt[j[2]] * (cnt[j[2]] + 1) / 2 * cnt[j[0]];
		}
		for (auto j : cool[3]) {
			ans += cnt[j[0]] * cnt[j[1]] * cnt[j[2]];
		}
		cout << ans << '\n';
	}
}