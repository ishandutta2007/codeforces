#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

#define vi vector <int>
#define ull unsigned long long
#define ll long long
#define pii pair<ull, int>
#define fr first
#define se second
const int MAXN = 100100;
const ull base = 123456789876543ull;
int n, m;

struct arr {
    int w; vi v;
    bool operator < (const arr &tmp) const { return w < tmp.w; }
} a[MAXN];

int sav[MAXN * 32];
vector <pii> h[MAXN];
void add (int id, int k) {
    for (auto i: h[id]) sav[i.fr] += k;
}
bool check (int mid) {
    int now = 0; long long ret = 0;
    for (int i = n; i >= 1; i--) {
        while (now < n && a[now + 1].w + a[i].w <= mid) add(++now, 1);
        for (auto j: h[i]) ret += j.se * sav[j.fr];
    }
    while (now) add(now--, -1);
    return ret;
}

ull b[MAXN * 32]; int bt;
inline int Hash (ull x) { return lower_bound(b + 1, b + bt + 1, x) - b; }

int main () {
    n = read(), m = read(); int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) a[i].v.push_back(read());
        sort(a[i].v.begin(), a[i].v.end());
        a[i].w = read();
    }
    sort(a + 1, a + n + 1);
    for (i = 1; i <= n; i++) {
        for (j = 0; j < (1 << m); j++) {
            ull tmp = 0; int tmp2 = 1;
            for (int k = 0; k < m; k++) if ((j >> k) & 1) tmp = (tmp * base + a[i].v[k]), tmp2 *= -1;
            h[i].push_back(pii(tmp, tmp2));
            b[++bt] = tmp;
        }
    }
    sort(b + 1, b + bt + 1); bt = unique(b + 1, b + bt + 1) - b - 1;
    for (i = 1; i <= n; i++) for (auto &j: h[i]) j.fr = Hash(j.fr);
    int ans = 2e9 + 7, L = 0, R = n;
    for (i = 1; i <= n; i++) add(i, 1);
    while (L < R) {
        add(++L, -1); bool hav = 0;
        while (L < R) {
            ll tmp = 0;
            for (auto i: h[L]) tmp += i.se * sav[i.fr];
            if (tmp) hav = 1, add(R--, -1); else break;
        }
        if (hav) ++R, ans = min(ans, a[L].w + a[R].w);
    }
    printf("%d\n", ans > 2e9 ? -1 : ans);
    return 0;
}