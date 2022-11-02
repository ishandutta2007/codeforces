#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,tree-vectorize")
#pragma GCC target("arch=skylake,tune=skylake")
#define _GLIBCXX_GTHREAD_USE_WEAK 0
#include <bits/stdc++.h>
#ifdef LOC
#include "debuglib.h"
#else
#define deb(...)
#define DBP(...)
#endif
using namespace std;

constexpr int MOD = int(1e9) + 7;

template<size_t N>
using vec = array<int, N>;

template<size_t N>
using matrix = array<vec<N>, N>;

template<size_t N>
matrix<N> ident() {
    matrix<N> mat = {};
    for (size_t i = 0; i < N; i++) {
        mat[i][i] = 1;
    }
    return mat;
}

template<size_t N>
matrix<N> mul(const matrix<N>& l, const matrix<N>& r) {
    matrix<N> ret = {};
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            __int128 tmp = 0;
            for (size_t k = 0; k < N; k++) {
                tmp += int64_t(l[i][k]) * r[k][j];
            }
            ret[i][j] = int(tmp % MOD);
        }
    }
    return ret;
}

template<size_t N>
vec<N> mul(const matrix<N>& l, const vec<N>& r) {
    vec<N> ret = {};
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            ret[i] = int((ret[i] + int64_t(l[i][j]) * r[j]) % MOD);
        }
    }
    return ret;
}

template<size_t N>
int dot(const vec<N>& l, const vec<N>& r) {
    int ret = 0;
    for (size_t i = 0; i < N; i++) {
        ret = int((ret + int64_t(l[i]) * r[i]) % MOD);
    }
    return ret;
}

template<size_t N>
matrix<N> pow(matrix<N> mat, int64_t p) {
    matrix<N> ret = ident<N>();
    while (p != 0) {
        if (p % 2 != 0) {
            ret = mul(ret, mat);
        }
        mat = mul(mat, mat);
        p /= 2;
    }
    return ret;
}

char getCharAt(int k) {
    constexpr long double goldenRatio = 1.6180339887498948482045868343656381177203091798057628621354486227;
    int val = 2 + int((k+1) * goldenRatio) - int((k+2) * goldenRatio);
    return char('b' - val);
}

int countMatches(const string& pat, int begin, int end) {
    int ret = 0;
    end -= int(pat.size());
    for (int i = begin; i <= end; i++) {
        bool ok = 1;
        for (int j = 0; j < int(pat.size()); j++) {
            if (pat[j] != getCharAt(i+j)) {
                ok = 0;
                break;
            }
        }
        ret += ok;
    }
    return ret;
}

int countMatchesThrough(const string& pat, int mid) {
    int n = int(pat.size());
    return countMatches(pat, mid-n+1, mid+n-1);
}

int run(int64_t n) {
    string w;
    cin >> w;
    n--;

    if (n == 0) {
        return w == "a";
    }

    int baseLen1 = 1, baseLen2 = 2;
    int offset = 1;

    while (baseLen1 < int(w.size())) {
        tie(baseLen1, baseLen2) = make_pair(baseLen2, baseLen1+baseLen2);
        offset++;
    }

    if (offset > n) {
        return 0;
    }

    if (offset == n) {
        return countMatches(w, 0, baseLen1);
    }

    matrix<4> transition = {{
        {1, 1, 0, 0}, // #A
        {1, 0, 0, 0}, // #B or #AB
        {0, 0, 0, 1}, // #AA
        {0, 1, 1, 0}, // #BA
    }};

    vec<4> start = { 1, 0, 0, 0 };

    vec<4> occurences = {
        countMatches(w, 0, baseLen2),                // in A
        countMatches(w, 0, baseLen1) + countMatchesThrough(w, baseLen2), // in B or through AB
        countMatchesThrough(w, baseLen1+baseLen2*2), // through AA
        countMatchesThrough(w, baseLen1+baseLen2),   // through BA
    };

    auto transitionPow = pow(transition, n-offset-1);
    auto counts = mul(transitionPow, start);
    int ans = dot(counts, occurences);
    return ans;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int64_t k; cin >> k;
    int t; cin >> t;

    while (t--) {
        int ans = run(k);
        ans %= MOD;
        if (ans < 0) {
            ans += MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}