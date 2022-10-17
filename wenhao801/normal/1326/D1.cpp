#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 1000100;
char a[MAXN], b[MAXN]; int n;

const int b1 = 1e4 + 7, m1 = 998244853, b2 = 101, m2 = 1e9 + 9;
int qpow(int x, int y, int mod) {
    int ret = 1;
    while (y) {
        if (y & 1) ret = 1ll * ret * x % mod;
        x = 1ll * x * x % mod; y >>= 1;
    }
    return ret;
}
struct Hash {
    bool rev;
    int h1[MAXN], h2[MAXN], p1[MAXN], ip1[MAXN], p2[MAXN], ip2[MAXN];
    int get1(int l, int r) { if (rev) swap(l, r), l = n - l + 1, r = n - r + 1; return (1ll * (h1[r] - 1ll * h1[l - 1] * p1[r - l + 1]) % m1 + m1) % m1; }
    int get2(int l, int r) { if (rev) swap(l, r), l = n - l + 1, r = n - r + 1; return (1ll * (h2[r] - 1ll * h2[l - 1] * p2[r - l + 1]) % m2 + m2) % m2; }
    void init(char *s) {
        for (int i = 1; i <= n; i++) h1[i] = (1ll * h1[i - 1] * b1 + s[i] - 'a' + 5) % m1;
        for (int i = 1; i <= n; i++) h2[i] = (1ll * h2[i - 1] * b2 + s[i] - 'a' + 5) % m2;
        p1[0] = p2[0] = ip1[0] = ip2[0] = 1;
        p1[1] = b1, ip1[1] = qpow(b1, m1 - 2, m1), p2[1] = b2, ip2[1] = qpow(b2, m2 - 2, m2);
        for (int i = 1; i <= n; i++)
            p1[i] = 1ll * p1[i - 1] * p1[1] % m1,
            ip1[i] = 1ll * ip1[i - 1] * ip1[1] % m1,
            p2[i] = 1ll * p2[i - 1] * p2[1] % m2,
            ip2[i] = 1ll * ip2[i - 1] * ip2[1] % m2;
    }
} ha, hb;

int main() {
    int T = read(); while (T--) {
        scanf("%s", a + 1); n = strlen(a + 1);
        int i, j;
        for (i = 1; i <= n; i++) b[i] = a[i];
        reverse(b + 1, b + n + 1);
        ha.init(a), hb.init(b); hb.rev = 1;
        int lim = 0; while (lim < n && a[lim + 1] == b[lim + 1]) ++lim;
        if (lim == n) { puts(a + 1); continue; }
        int ansr = lim, ansl = n - lim + 1;
        for (i = 1; i <= n; i++) {
            int L = 1, R = min(n - i + 1, i), res = 0;
            while (L <= R) {
                int mid = (L + R) >> 1;
                if (ha.get1(i - mid + 1, i) == hb.get1(i, i + mid - 1) &&
                    ha.get2(i - mid + 1, i) == hb.get2(i, i + mid - 1))
                    res = mid, L = mid + 1;
                else R = mid - 1;
            }
            int l = i - res + 1, r = i + res - 1, pos = min(l - 1, n - r);
            if (pos <= lim && pos * 2 + r - l + 1 >= ansr + (n - ansl + 1)) {
                if (l - 1 == pos) ansr = r, ansl = n - pos + 1;
                else ansr = pos, ansl = l;
            }
        }
        for (i = 1; i < n; i++) {
            int L = 1, R = min(n - i, i), res = 0;
            while (L <= R) {
                int mid = (L + R) >> 1;
                if (ha.get1(i - mid + 1, i) == hb.get1(i + 1, i + 1 + mid - 1) &&
                    ha.get2(i - mid + 1, i) == hb.get2(i + 1, i + 1 + mid - 1))
                    res = mid, L = mid + 1;
                else R = mid - 1;
            }
            if (!res) continue;
            int l = i - res + 1, r = i + 1 + res - 1, pos = min(l - 1, n - r);
            if (pos <= lim && pos * 2 + r - l + 1 >= ansr + (n - ansl + 1)) {
                if (l - 1 == pos) ansr = r, ansl = n - pos + 1;
                else ansr = pos, ansl = l;
            }
        }
        for (i = 1; i <= ansr; i++) putchar(a[i]);
        for (i = ansl; i <= n; i++) putchar(a[i]);
        putchar('\n');
    }
    return 0;
}