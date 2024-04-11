#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cassert>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 200200;
struct rng {
    int l, r, id;
    bool operator < (const rng &tmp) const {
        return r > tmp.r;
    }
} a[MAXN];
int n, b[MAXN];

bool cmp1 (rng x, rng y) {
    if (x.l == y.l) return x.r < y.r;
    return x.l < y.l;
}
bool cmp2 (rng x, rng y) { return x.id < y.id; }

priority_queue <rng> pq;

int t[MAXN], pos[MAXN];
inline int lowbit (int x) { return x & -x; }
inline int query (int x) { int ret = 0; while (x) ret = (a[t[x]].r > a[ret].r ? t[x] : ret), x -= lowbit(x); return ret; }
inline void upd (int x, int k) { while (x <= n) t[x] = (a[k].r > a[t[x]].r ? k : t[x]), x += lowbit(x); }

int main () {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) a[i].id = i, a[i].l = read(), a[i].r = read();
    sort(a + 1, a + n + 1, cmp1);
    for (i = 1, j = 1; i <= n; i++) {
        while (j <= n && a[j].l == i) pq.push(a[j++]);
        assert(pq.top().r >= i);
        b[pq.top().id] = i; pos[i] = pq.top().id; pq.pop();
    }
    sort(a + 1, a + n + 1, cmp2);
    for (i = 1; i <= n; i++) {
        int ret = query(n - a[pos[i]].l + 1);
        if (a[ret].r >= i) {
            puts("NO"); ret = b[ret];
            for (j = 1; j <= n; j++) printf("%d%c", b[j], " \n"[j == n]);
            for (j = 1; j <= n; j++) {
                if (b[j] == ret) printf("%d%c", i, " \n"[j == n]);
                else if (b[j] == i) printf("%d%c", ret, " \n"[j == n]);
                else printf("%d%c", b[j], " \n"[j == n]);
            }
            return 0;
        }
        upd(n - i + 1, pos[i]);
    }
    puts("YES");
    for (i = 1; i <= n; i++) printf("%d%c", b[i], " \n"[j == n]);
    return 0;
}