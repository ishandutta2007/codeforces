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
#include <complex>
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
typedef complex<double> comp;

const int N = 3e5 + 1;

int ans = 1e9;
int n;
bool used[N];
int dev[N], dv[N];
vector<int> who[N];
vector<int> pd[N];
int d[N];
int dp[128];

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    for (int i = 2; i < N; ++i) {
        if (dev[i] == 0) {
            for (long long j = 1LL * i * i; j < N; j += i) {
                dev[j] = i;
            } 
        }
    }
    for (int i = 0; i < (1 << 7); ++i) {
        for (int j = 0; j < (1 << 7); ++j) {
            if ((i & j) == j && i != j) {
                pd[i].pb(j);
            }
        }
    } 
    cin >> n;
    for (int i = 0; i < n; ++i) {
        vector<int> cur;
        int V;
        cin >> V;
        // if (used[V]) continue;
        int c = V, K = 1;
        while (dev[c] != 0) {
            cur.pb(dev[c]);
            K *= cur.back();
            while (c % cur.back() == 0) {
                c /= cur.back();
            }
        }
        if (dev[c] == 0 && c != 1) cur.pb(c);
        // if (used[K]) continue;
        used[V] = true;
        for (int j = 0; j < (1 << cur.size()); ++j) {
            int d = 1;
            for (int q = 0; q < cur.size(); ++q) {
                if ((j >> q) & 1) {
                    d *= cur[q];
                }
            }
            ::d[j] = dv[d];
            ++dv[d];
        }
        for (int j = (1 << cur.size()); j--;) {
            if (d[j] == 0) continue;
            for (int q : pd[j]) {
                d[q] -= d[j];
            }
        }
        for (int j = 0; j < (1 << cur.size()); ++j) dp[j] = 1e9;
        dp[(1 << cur.size()) - 1] = 0;
        for (int j = 0; j < (1 << cur.size()); ++j) {
            if (d[j] == 0) continue;
            for (int q = 0; q < (1 << cur.size()); ++q) {
                chkmin(dp[q & j], dp[q] + 1);
            }
        }
        chkmin(ans, dp[0] + 1);
    }
    if (ans > n) ans = -1;
    cout << ans << '\n';
}