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

const int MAXN = 600600;

int n, L, R;
int a[MAXN] = {};
int b[MAXN] = {};
int cnt = 0;

int Hash (int x) { return lower_bound(b + 1, b + cnt + 1, x) - b; }
int tree[MAXN];
int lowbit (int x) { return x & -x; }
void add (int x) { while (x <= cnt) tree[x]++, x += lowbit(x); }
int query (int x) { int ret = 0; while (x) ret += tree[x], x -= lowbit(x); return ret; }

signed main () {
    n = read(), L = -200000000000001ll, R = read() - 1;
    int i, j;
    for (i = 1; i <= n; i++) a[i] = b[++cnt] = read() + a[i - 1], b[++cnt] = a[i] - L, b[++cnt] = a[i] - R;
    b[cnt - 2] = 0;
    sort(b + 1, b + cnt + 1);
    cnt = unique(b + 1, b + cnt + 1) - b - 1; add(Hash(0));
    int ans = 0;
    for (i = 1; i <= n; i++) ans += query(Hash(a[i] - L)) - query(Hash(a[i] - R) - 1), add(Hash(a[i]));
    printf("%lld\n", ans);
    return 0;
}