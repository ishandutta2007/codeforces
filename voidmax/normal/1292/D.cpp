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

const int N = 5.1e3;
const int P = 700;

vector<int> prime;
int cnt[N];
int maxp[N];

int dp[N][P], cur[P], w[N], it[N];
vector<int> who;

int cool[P];

int n;
long long ans = 4e18;

void solve(int L, int R, long long cnt_dist = 0, long long cnt_rest = 0) {
    while (true) {
        long long cur_ans = cnt_dist;
        for (int M = L; M < R; ++M) {
            cur_ans += 1LL * cnt[who[M]] * w[who[M]];
        }
        chkmin(ans, cur_ans);
        memset(cool, 0, sizeof(cool));
        for (int M = L; M < R; ++M) {
            int v = who[M];
//            cout << v << ' ' << cnt[v] << ' ' << w[v] << '\n';
            while (it[v] >= 0 && dp[v][it[v]] == 0) {
                --it[v];
            }
            if (it[v] != -1) {
//                cout << prime[it[v]] << '\n';
                cool[it[v]] += cnt[v];
            }
        }
//        cout << '\n';
        int nxt = -1;
        for (int i = 0; i < P; ++i) {
            if (cool[i] > n / 2) {
                nxt = i;
                break;
            }
        }
        if (nxt == -1) return;
//        cout << "prime: " << prime[nxt] << ' ' << cnt_rest << ' ' << cnt_dist << '\n';
        while (it[who[L]] != nxt) {
            cnt_dist += 1LL * cnt[who[L]] * w[who[L]];
            cnt_rest += cnt[who[L]];
            ++L;
        }
        while (it[who[R - 1]] != nxt) {
            --R;
            cnt_dist += 1LL * cnt[who[R]] * w[who[R]];
            cnt_rest += cnt[who[R]];
        }
        for (int M = L; M < R; ++M) {
            --w[who[M]];
            --dp[who[M]][it[who[M]]];
        }
        cnt_dist += cnt_rest;
    }
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    memset(maxp, -1, sizeof(maxp));
    for (int i = 2; i < N; ++i) {
        if (maxp[i] == -1) {
            maxp[i] = prime.size();
            prime.pb(i);
            for (int j = i; j < N; j += i) {
                chkmax(maxp[j], maxp[i]);
            }
        }
    }
    cin >> n;
//    n = 1e6;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
//        v = i % 5000 + 1;
        ++cnt[v];
    }
    for (int i = 0; i < N; ++i) {
        if (cnt[i]) who.pb(i);
        it[i] = prime.size();
    }
    for (int i = 1; i <= 5000; ++i) {
        int w = i;
        while (w != 1) {
            cur[maxp[w]]++;
            w /= prime[maxp[w]];
        }
        for (int j = 0; j < prime.size() && prime[j] <= i; ++j) {
            dp[i][j] = cur[j];
            ::w[i] += cur[j];
        }
    }
    solve(0, who.size());
    cout << ans << '\n';
//    cout << 1. * clock() / CLOCKS_PER_SEC << '\n';
}