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

const int p = 998244353; // 2^23 * 7 * 17 - 1

int sum(int a, int b) { 
    a += b;
    return a < p ? a : a - p;
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

const int wp = powx(3, 7 * 17); // w^(2^23) == 1

namespace fft {
    int k;
    vector<int> rev;
    vector<int> st;

    void fft(vector<int> &a) {
        for (int i = 0; i < k; i++)
            if (rev[i] < i)
                swap(a[rev[i]], a[i]);
        int w, wn, ai, aj;
        for (int s = 1, it = 0; s < k; s <<= 1, it++) {
            wn = st[it];
            for (int l = 0; l < k; l += s + s) {
                w = 1;
                for (int i = l, j = l + s; i < l + s; i++, j++) {
                    ai = a[i];
                    aj = 1LL * w * a[j] % p; // or st[((1 << 22) / s) * (i - l)]
                    a[i] = ai + aj;
                    if (a[i] >= p)
                        a[i] -= p;
                    a[j] = ai - aj;
                    if (a[j] < 0)
                        a[j] += p;
                    w = 1LL * w * wn % p;
                }
            }
        }
    }

    vector<int> mult(vector<int> a, vector<int> b) {
        k = 1;
        while (k < (int)a.size() + (int)b.size() - 1)
            k <<= 1;
        st.clear();
        st.push_back(powx(wp, ((1 << 22) / k)));
        for (int t = 1; t < k; t <<= 1)
            st.push_back(1LL * st.back() * st.back() % p);
        reverse(st.begin(), st.end());
        rev.clear();
        rev.resize(k);
        rev[0] = 0;
        for (int i = 1; i < k; i++) {
            if (i & 1)
                rev[i] = rev[i - 1] + (k >> 1);
            else
                rev[i] = rev[i >> 1] >> 1;
        }
        a.resize(k);
        fft(a);
        b.resize(k);
        fft(b);
        vector<int> pr(k);
        for (int i = 0; i < k; i++)
            pr[i] = 1LL * a[i] * b[i] % p;
        fft(pr);
        reverse(pr.begin() + 1, pr.end());
        int inv_k = powx(k, p - 2);
        for (int i = 0; i < k; i++)
            pr[i] = 1LL * pr[i] * inv_k % p;
        while (pr.back() == 0)
            pr.pop_back(); // can be removed
        return pr;
    }
}

const int N = 2e5 + 5;

int f[2][N];

int n, k;

int main() {
    ios::sync_with_stdio(0);
    srand(time(0));
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    f[0][0] = 1;
    for (int i = 1; i < N; ++i) {
        f[0][i] = mul(i, f[0][i - 1]);
    }
    f[1][N - 1] = powx(f[0][N - 1], p - 2);
    for (int i = N - 1; i >= 1; --i) {
        f[1][i - 1] = mul(i, f[1][i]);
    }
    cin >> n >> k;
    vector<int> a(k + 1, 0), b(k + 1, 0);
    for (int i = 0; i <= k; ++i) {
        a[i] = mul(powx(i, k), f[1][i]);
        b[i] = f[1][i];
        if (i & 1) b[i] = sum(p - b[i], 0);
    }
    vector<int> res = fft::mult(a, b);
    res.resize(k + 1);  
    int ans = 0;
    int cnk = 1;
    for (int i = 1; i <= n && i <= k; ++i) {
        cnk = mul(cnk, n - i + 1);
        int cur = mul(mul(res[i], cnk), powx(n + 1, n - i));
        ans = sum(cur, ans);
    }
    cout << ans << '\n';
}