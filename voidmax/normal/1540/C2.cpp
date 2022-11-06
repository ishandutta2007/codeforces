#pragma GCC optimize("O3")
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

const int N = 1.1e2;
const int M = 1.1e4;
const int p = 1e9 + 7;

int sum(int a, int b) {
    a += b;
    return a >= p ? a - p : a;
}

int mul(long long a, int b) {
    return a * b % p;
}

int powx(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = mul(ans, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}

int n;
int b[N], c[N];
int pref[N * N], res[N * N];
int ans[M * 2];

void solve(int x) {
    memset(pref, 0, sizeof(pref));
    for (int i = x; i <= c[0]; ++i) {
        pref[i] = 1;
    }
    int sumb = 0, total = 0;
    for (int i = 1; i < n; ++i) {
        sumb += b[i - 1];
        total += sumb;
        memset(res, 0, sizeof(res));
        int rest = 1;
        for (int j = i + 1; j < n; ++j) {
            rest = mul(rest, c[j] + 1);
        }
        for (int j = 0; j < N * N; ++j) {
            if (pref[j]) {
                for (int q = 0; q <= c[i]; ++q) {
                    if (j + q - total >= x * (i + 1)) {
                        res[j + q] = sum(res[j + q], pref[j]);
                    } 
                }
            }
            pref[j] = res[j];
        }
    }
    x += M;
    ans[x] = 0;
    for (int i = 0; i < N * N; ++i) {
        ans[x] = sum(ans[x], pref[i]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i + 1 < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i <= c[0]; ++i) {
        pref[i] = 1;
    }
    int suma = c[0], sumb = 0, total = 0;
    long double L = 0, R = c[0];
    for (int i = 1; i < n; ++i) {
        suma += c[i];
        sumb += b[i - 1];
        total += sumb;
        chkmin(L, 1. * (0    - total) / (i + 1));
        chkmin(R, 1. * (suma - total) / (i + 1));
    }
    L -= 5;
    R += 5;
    L = round(L);
    R = round(R);
    for (int M = L; M <= R; ++M) {
        solve(M);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int v;
        cin >> v;
        if (v < L) v = L;
        if (v > R) v = R;
        cout << ans[v + M] << '\n';
    }
}