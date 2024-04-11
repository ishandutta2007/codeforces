#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10, mod = 1e9 + 7, inf = maxn;
// string s[maxn];
char s[maxn][maxn];
int uz[maxn][maxn], lz[maxn][maxn], rz[maxn][maxn], bz[maxn][maxn];
int ulz[maxn][maxn], urz[maxn][maxn], blz[maxn][maxn], brz[maxn][maxn];

inline int fpow(int a, int n) {
    int ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = ret * 1ll * a % mod;
        a = a * 1ll * a % mod;
    }
    return ret;
}

struct data {
    long double lg;
    int pr, dv, zero = 0;
    data(int a) {
        if (a == 0) zero = 1, lg = 0, pr = 1, dv = 1;
        else lg = log(a), pr = a, zero = 0, dv = 1;
    }
    data(long double a, int b): lg(a), pr(b), dv(1) { zero = (pr == 0); }
    data(long double a, int b, int d, int c): lg(a), pr(b), dv(d), zero(c) {}
    data(): lg(0), pr(1), zero(0), dv(1) {}
    data operator+(const data &rhs) const { return data(lg + rhs.lg, pr * 1ll * rhs.pr % mod, dv * 1ll * rhs.dv % mod, zero + rhs.zero); }
    data operator-(const data &rhs) const { return data(lg - rhs.lg, pr * 1ll * rhs.dv % mod, dv * 1ll * rhs.pr % mod, zero - rhs.zero); }
    bool operator<(const data &rhs) const { return zero ? true : rhs.zero ? false : lg < rhs.lg; }
    bool operator>(const data &rhs) const { return zero ? false : rhs.zero ? true : lg > rhs.lg; }
};

data up[maxn][maxn], bp[maxn][maxn], lp[maxn][maxn], rp[maxn][maxn];
data ulp[maxn][maxn], urp[maxn][maxn], blp[maxn][maxn], brp[maxn][maxn];

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);
    int n; // cin >> n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%s", s + i);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == '0') uz[i][j] = 0;
            else if (i == 0) uz[i][j] = 1;
            else uz[i][j] = uz[i - 1][j] + 1;
            up[i][j] = data(s[i][j] - '0');
            if (i > 0) up[i][j] = up[i][j] + up[i - 1][j];
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == '0') bz[i][j] = 0;
            else if (i == n - 1) bz[i][j] = 1;
            else bz[i][j] = bz[i + 1][j] + 1;
            bp[i][j] = data(s[i][j] - '0');
            if (i < n - 1) bp[i][j] = bp[i][j] + bp[i + 1][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == '0') lz[i][j] = 0;
            else if (j == 0) lz[i][j] = 1;
            else lz[i][j] = lz[i][j - 1] + 1;
            lp[i][j] = data(s[i][j] - '0');
            if (j > 0) lp[i][j] = lp[i][j] + lp[i][j - 1];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            if (s[i][j] == '0') rz[i][j] = 0;
            else if (j == n - 1) rz[i][j] = 1;
            else rz[i][j] = rz[i][j + 1] + 1;
            rp[i][j] = data(s[i][j] - '0');
            if (j < n - 1) rp[i][j] = rp[i][j] + rp[i][j + 1];
        }
    }
    data ans = data(0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) if (s[i][j] != '0') {
            // cout << "i = " << i << " j = " << j << endl;
            int e = min({ lz[i][j], rz[i][j], uz[i][j], bz[i][j] });
            int ud = min(e, i + 1);
            data a = ((i - ud < 0) ? up[i][j] : up[i][j] - up[i - ud][j]);
            int bd = min(e, n - i);
            data b = ((i + bd >= n) ? bp[i][j] : bp[i][j] - bp[i + bd][j]);
            int ld = min(e, j + 1);
            data c = ((j - ld < 0) ? lp[i][j] : lp[i][j] - lp[i][j - ld]);
            int rd = min(e, n - j);
            data d = ((j + rd >= n) ? rp[i][j] : rp[i][j] - rp[i][j + rd]);
            data res = (((a + b) + c) + d);
            res = res - data(s[i][j] - '0');
            res = res - data(s[i][j] - '0');
            res = res - data(s[i][j] - '0');
            if (ans.zero || res.lg > ans.lg) ans = res;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == '0') ulz[i][j] = 0;
            else if (i == 0 || j == 0) ulz[i][j] = 1;
            else ulz[i][j] = ulz[i - 1][j - 1] + 1;
            ulp[i][j] = data(s[i][j] - '0');
            if (i > 0 && j > 0) ulp[i][j] = ulp[i][j] + ulp[i - 1][j - 1];
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == '0') blz[i][j] = 0;
            else if (i == n - 1 || j == 0) blz[i][j] = 1;
            else blz[i][j] = blz[i + 1][j - 1] + 1;
            blp[i][j] = data(s[i][j] - '0');
            if (i < n - 1 && j > 0) blp[i][j] = blp[i][j] + blp[i + 1][j - 1];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            if (s[i][j] == '0') urz[i][j] = 0;
            else if (i == 0 || j == n - 1) urz[i][j] = 1;
            else urz[i][j] = urz[i - 1][j + 1] + 1;
            urp[i][j] = data(s[i][j] - '0');
            if (i > 0 && j < n - 1) urp[i][j] = urp[i][j] + urp[i - 1][j + 1];
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (s[i][j] == '0') brz[i][j] = 0;
            else if (i == n - 1 || j == n - 1) brz[i][j] = 1;
            else brz[i][j] = brz[i + 1][j + 1] + 1;
            brp[i][j] = data(s[i][j] - '0');
            if (i < n - 1 && j < n - 1) brp[i][j] = brp[i][j] + brp[i + 1][j + 1];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) if (s[i][j] != '0') {
            int e = min({ ulz[i][j], urz[i][j], blz[i][j], brz[i][j] });
            int uld = min(e, min(i + 1, j + 1));
            data a = ((i - uld < 0 || j - uld < 0) ? ulp[i][j] : ulp[i][j] - ulp[i - uld][j - uld]);
            int bld = min(e, min(n - i, j + 1));
            data b = ((i + bld >= n || j - bld < 0) ? blp[i][j] : blp[i][j] - blp[i + bld][j - bld]);
            int urd = min(e, min(i + 1, n - j));
            data c = ((i - urd < 0 || j + urd >= n) ? urp[i][j] : urp[i][j] - urp[i - urd][j + urd]);
            int brd = min(e, min(n - i, n - j));
            data d = ((i + brd >= n || j + brd >= n) ? brp[i][j] : brp[i][j] - brp[i + brd][j + brd]);
            data res = (((a + b) + c) + d);
            res = res - data(s[i][j] - '0');
            res = res - data(s[i][j] - '0');
            res = res - data(s[i][j] - '0');
            if (ans.zero || res.lg > ans.lg) ans = res;
        }
    }
    if (ans.zero) puts("0");
    else printf("%d\n", ans.pr * 1ll * fpow(ans.dv, mod - 2) % mod);
}