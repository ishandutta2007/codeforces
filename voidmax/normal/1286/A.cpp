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
int L, R;
vector<int> a;

int dp[101][2][101][101];

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    cin >> n;
    a.resize(n);
    cin >> a;
   	L = n / 2;
   	R = n - L;
   	for (auto i : a) {
   		if (i == 0) continue;
   		if (i & 1) --R;
   		else       --L;
   	}
   	for (int i = 0; i <= n; ++i) {
   		for (int j = 0; j <= L; ++j) {
   			for (int q = 0; q <= R; ++q) {
   				dp[i][0][j][q] = 1e9;
   				dp[i][1][j][q] = 1e9;
   			}
   		}
   	}
   	dp[0][0][0][0] = 0;
   	dp[0][1][0][0] = 0;
   	for (int i = 0; i < n; ++i) {
   		for (int j = 0; j <= L; ++j) {
   			for (int q = 0; q <= R; ++q) {
   				if (a[i] != 0) {
   					if (a[i] & 1) {
   						chkmin(dp[i + 1][1][j][q], dp[i][1][j][q]);
   						chkmin(dp[i + 1][1][j][q], dp[i][0][j][q] + 1);
   					} else {
   						chkmin(dp[i + 1][0][j][q], dp[i][0][j][q]);
   						chkmin(dp[i + 1][0][j][q], dp[i][1][j][q] + 1);
   					}
   				} else {
   					chkmin(dp[i + 1][1][j][q + 1], dp[i][1][j][q]);
   					chkmin(dp[i + 1][1][j][q + 1], dp[i][0][j][q] + 1);
   					chkmin(dp[i + 1][0][j + 1][q], dp[i][0][j][q]);
   					chkmin(dp[i + 1][0][j + 1][q], dp[i][1][j][q] + 1);
   				}
   			}
   		}
   	}
   	cout << min(dp[n][0][L][R], dp[n][1][L][R]) << '\n';
}