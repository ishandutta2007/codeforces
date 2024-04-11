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

const int N = 1 << 19;
const int p = 1e9 + 7;

struct seg_tree_no_mod {
    long long t[N * 2 + 1];

    void change(int i, long long v) {
        i += N;
        while (i > 0) {
            t[i] += v;
            i >>= 1;
        }
    }

    long long k;

    long long gets(int i, int L, int R, int Ln, int Rn) {
        if (Ln <= L && R <= Rn) {
            return t[i];
        }
        if (Rn <= L || R <= Ln) {
            return 0;
        }
        int M = (L + R) >> 1;
        return gets(i * 2, L, M, Ln, Rn) + gets(i * 2 + 1, M, R, Ln, Rn);
    }

    int get(int i, int L, int R, int Ln, int Rn) {
        if (R <= Ln || Rn <= L) return -1;
        if (Ln <= L && R <= Rn) {
            if (k > t[i]) {
                k -= t[i];
                return -1;
            }
        }
        if (L + 1 == R) {
            return i - N;
        }
        int M = (L + R) >> 1;
        int ans = get(i * 2, L, M, Ln, Rn);
        if (ans != -1) return ans;
        return get(i * 2 + 1, M, R, Ln, Rn);
    }

    int get(int L, int R, long long _k) {
        k = _k;
        return get(1, 0, N, L, R);
    }
} box;

int sum(int a, int b) {
    a += b;
    return a < p ? a : a - p;
}

int mul(long long a, int b) {
    return a * b % p;
}

struct seg_tree_with_mod {
    int t[N * 2 + 1];

    void change(int i, int v) {
        i += N;
        while (i > 0) {
            t[i] = sum(t[i], v);
            i >>= 1;
        }
    }

    int gets(int i, int L, int R, int Ln, int Rn) {
        if (Ln <= L && R <= Rn) {
            return t[i];
        }
        if (Rn <= L || R <= Ln) {
            return 0;
        }
        int M = (L + R) >> 1;
        return sum(gets(i * 2, L, M, Ln, Rn), gets(i * 2 + 1, M, R, Ln, Rn));
    }
} sumx[2];

const int RN = 1e9;

int n, m;
int a[N];
int w[N];

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        box.change(i, w[i]);
        sumx[0].change(i, mul(a[i] - i, w[i]));
        sumx[1].change(i, mul(RN + i + 1 - n - a[i], w[i]));
    }
    for (int i = 0; i < m; ++i) {
        int L, R;
        cin >> L >> R;
        if (L < 0) {
            L = -L - 1;
            int k = sum(R, p - w[L]);
            box.change(L, R - w[L]);
            sumx[0].change(L, mul(a[L] - L, k));
            sumx[1].change(L, mul(RN + L + 1 - n - a[L], k));
            w[L] = R;
        } else {
            --L;
            long long s = box.gets(1, 0, N, L, R);
            long long half = (s + 1) / 2;
            int M = box.get(L, R, half);
            long long sumL = half - box.k;
            long long sumR = s - sumL - w[M];
            long long wL = M - L >= 1 ? sumx[0].gets(1, 0, N, L, M) : 0;
            long long wR = R - M - 1 >= 1 ? sumx[1].gets(1, 0, N, M + 1, R) : 0;
            int coorL = a[M] + L - M, coorR = a[M] + R - M - 1;
            int curL = L, curR = RN + R + 1 - n - 1;
            int ans =      sum(mul(sumL % p, sum(coorL, p - curL)), p - wL);
            if (M - L < 1) ans = 0;
            auto last = ans;
            if (R - M - 1 >= 1) ans = sum(ans, sum(mul(sumR % p, sum(curR, p - coorR)), p - wR));
            cout << ans << '\n'; 
        }
    }
}