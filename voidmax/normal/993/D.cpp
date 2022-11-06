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
#ifdef ON_PC
#define _getchar_nolock getchar_unlocked
#endif
using namespace std;
	  //g++ -o file --std=c++11 -D ON_PC
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

// int ri() {
// 	int v = 0;
// 	char c = _getchar_nolock();
// 	while ('0' <= c && c <= '9') {
// 		v = (v << 3) + (v << 1) + c - '0';
// 		c = _getchar_nolock();
// 	}
// 	return v;
// }

const int MAXN = 1e5 + 1;

int n;
vector<int> a, b;
long long dp[2][5001][27];

void clear(int t) {
	for (int i = 0; i <= 5000; ++i) {
		for (int j = 0; j <= 26; ++j) {
			dp[t][i][j] = 1e15;
		}
	}
}

vector<int> id;

bool cmp(int i, int j) {
	if (a[i] != a[j]) {
		return a[i] > a[j];
	}
	return b[i] > b[j];
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	a.resize(n);
	b.resize(n);
	cin >> a >> b;
	for (int i = 0; i < n; ++i) {
		id.pb(i);
	}
	sort(id.begin(), id.end(), cmp);
	clear(0);
	dp[0][0][0] = 0;
	int cur_sum = 0;
	int L = 0;
	while (L < id.size()) {
		int R = L;
		while (R < id.size() && a[id[R]] == a[id[L]]) {
			++R;
		}
		vector<long long> A, B, C;
		A.pb(0);
		B.pb(0);
		C.pb(R - L);
		for (int M = L; M < R; ++M) {
			A.pb(A.back() + a[id[M]]);
			B.pb(B.back() + b[id[M]]);
			C.pb(C.back() - 1);
		}
		clear(1);
		//cout << dp[0][cur_sum][q] << ' ' << cur_sum << endl;
		for (int i = 0; i < C.size(); ++i) {
			for (int sumw = 0; sumw <= cur_sum; ++sumw) {
				for (int rest = C[i]; rest <= 25; ++rest) {
					chkmin(dp[1][sumw + B[i]][min(rest - (int)C[i] + i, 25)], dp[0][sumw][rest] + A[i]); 
				}
			}
		}
		cur_sum += B.back();
		//cout << "?" << dp[0][cur_sum][0] << ' ' << dp[1][cur_sum + b[i]][1] << endl;
		for (int i = 0; i <= cur_sum; ++i) {
			for (int j = 0; j <= 25; ++j) {
				dp[0][i][j] = dp[1][i][j];
			}
		}
		L = R;
	}
	long long ansL = 1e8, ansR = 1;
	for (int i = 1; i <= cur_sum; ++i) {
		for (int j = 0; j <= 25; ++j) {
			if (dp[0][i][j] > 1e14) continue;
			long long aL = dp[0][i][j], aR = i;
			//cout << aL << ' ' << aR << endl;
			if (ansL * aR > aL * ansR) {
				ansL = aL;
				ansR = aR;
			}
  		}
	}
	cout << (ansL * 1000 + ansR - 1) / ansR << '\n';
}