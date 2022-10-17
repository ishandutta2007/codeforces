#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

using ll = long long;
#define pii pair <int, int>
#define fr first
#define se second

const int MAXN = 400400, lim = 400000;
int n; pii a[MAXN];
ll ans;

int premin[MAXN], premax[MAXN], sufmin[MAXN], sufmax[MAXN];
void solve (bool tag) {
    int i, j;
    for (i = 0; i <= lim; i++) premin[i] = sufmin[i] = 1e9, premax[i] = sufmax[i] = -1e9;
    for (i = 1; i <= n; i++) if (((a[i].fr + a[i].se) & 1) != tag) {
        int x = (a[i].se + 1 - a[i].fr) >> 1, y = (a[i].se + 1 + a[i].fr) >> 1;
        x += lim >> 1, y += lim >> 1;
        premin[x] = min(premin[x], y); premax[x] = max(premax[x], y - 1);
        sufmin[x - 1] = min(sufmin[x - 1], y); sufmax[x - 1] = max(sufmax[x - 1], y - 1);
    }
    for (i = 1; i <= lim; i++) premin[i] = min(premin[i - 1], premin[i]), premax[i] = max(premax[i - 1], premax[i]);
    for (i = lim - 1; i >= 0; i--) sufmin[i] = min(sufmin[i + 1], sufmin[i]), sufmax[i] = max(sufmax[i + 1], sufmax[i]);
    for (i = 0; i <= lim; i++) {
        int l = max(premin[i], sufmin[i]), r = min(premax[i], sufmax[i]);
        if (l <= r) ans += r - l + 1;
    }
}

int main () {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) a[i].fr = read(), a[i].se = read();
    solve(0), solve(1);
    printf("%lld\n", ans);
    return 0;
}