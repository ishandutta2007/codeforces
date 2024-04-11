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
#include <iostream>
#include <complex>
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
#include <stack>
#include <deque>
#include <random>
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

const int INF = 1e9;
const int N = 1e6;

int n, m;
int have[N];

vector<vector<int>> get(int L, int R) {
    if (R - L == 1) {
        return {{-INF, -INF}, {1, -INF}};
    }
    if (R - L == 2) {
        int cnt = have[L] + have[L + 1];
        if (cnt == 0) {
            return {{0, -INF}, {-INF, -INF}};
        }
        if (cnt == 1) {
            return {{-INF, 1}, {1, -INF}};
        }
        if (cnt == 2) {
            return {{-INF, -INF}, {-INF, 1}};
        }
        assert(false);
    }
    int M = (L + R) >> 1;
    auto dp1 = get(L, M);
    auto dp2 = get(M, R);
    vector<vector<int>> ans_dp = {{-INF, -INF}, {-INF, -INF}};
    for (int w1 : {0, 1}) {
        for (int w2 : {0, 1}) {
            for (int l1 : {0, 1}) {
                for (int l2 : {0, 1}) {
                    for (int mask = 0; mask < 8; ++mask) {
                        vector<int> val = {w1, w2, l1, l2};
                        int cnt = 0;
                        cnt = val[2] | val[3];
                        if (mask & 1) swap(val[2], val[3]);
                        cnt += val[0] | val[1];
                        if (mask & 2) swap(val[0], val[1]);
                        cnt += val[1] | val[2];
                        if (mask & 4) swap(val[1], val[2]);
                        chkmax(ans_dp[val[0]][val[1]], dp1[w1][l1] + dp2[w2][l2] + cnt);
                    }
                }
            }
        }
    }
    return ans_dp;
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    cin >> n >> m;
    if (m == 0) {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 0; i < m; ++i) {
        int id;
        cin >> id;
        have[id - 1] = true;
    }
    auto dp = get(0, (1 << n));
    int ans = -INF;
    for (int w1 : {0, 1}) {
        for (int l1 : {0, 1}) {
            chkmax(ans, dp[w1][l1] + (w1 | l1));
        }
    }
    cout << ans << '\n';
}