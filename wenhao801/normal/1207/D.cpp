#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define int long long

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 300300;
const int mod = 998244353;

int n;

struct ele {
    int a;
    int b;
} s[MAXN] = {};

int ans = 1;
int S = 1;

bool cmp1 (ele x, ele y) { return x.a < y.a; }
bool cmp2 (ele x, ele y) { return x.b < y.b; }
bool cmp3 (ele x, ele y) { if (x.a < y.a) return true; else if (x.a == y.a && x.b < y.b) return true; return false;}

int frac (int x) { int ret = 1; for (int i = 1; i <= x; i++) ret = (ret * i) % mod; return ret; }

signed main () {
    n = read();
    int i, j;
    for (i = 1; i <= n; i++) s[i].a = read(), s[i].b = read();
    ans = frac(n);
    int pre = -1;
    sort(s + 1, s + n + 1, cmp1);
    //cout << ans << endl;
    int t = 1;
    for (i = 1; i <= n; i++) {
        if (pre == s[i].a) {
            t++;
        }
        else {
            S = (S * frac(t)) % mod;
            t = 1;
            pre = s[i].a;
        }
    }
    S = (S * frac(t)) % mod;
    ans = (ans - S + mod) % mod;
    //cout << ans << endl;
    pre = -1, S = 1, t = 1;
    sort(s + 1, s + n + 1, cmp2);
    for (i = 1; i <= n; i++) {
        if (pre == s[i].b) t++;
        else {
            S = (S * frac(t)) % mod;
            t = 1;
            pre = s[i].b;
        }
    }
    S = (S * frac(t)) % mod;
    ans = (ans - S + mod) % mod;
    //cout << ans << endl;
    sort(s + 1, s + n + 1, cmp3);
    pre = 0, S = 1, t = 1;
    for (i = 1; i <= n; i++) {
        if (s[i].a < s[i - 1].a || s[i].b < s[i - 1].b) { S = 0; break; }
        if (s[pre].a == s[i].a && s[pre].b == s[i].b) t++;
        else {
            S = (S * frac(t)) % mod;
            t = 1;
            pre = i;
        }
    }
    S = (S * frac(t)) % mod;
    ans = (ans + S) % mod;
    printf("%d\n", ans);
    return 0;
}