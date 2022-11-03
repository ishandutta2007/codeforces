#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int Case, n, sa, sb, da, db, de[N];
int fi[N], a[N << 1], ne[N << 1], tot;
inline void Add(int x, int y) {
    a[++tot] = y; ne[tot] = fi[x]; fi[x] = tot;
}
int max_len;
inline int GetDe(int x, int fa) {
    de[x] = de[fa] + 1;
    int mx = 0, mx2 = 0;
    for (int i = fi[x]; i; i = ne[i]) if (a[i] != fa) {
        int nv = GetDe(a[i], x) + 1;
        if (nv > mx) mx2 = mx, mx = nv;
        else if (nv > mx2) mx2 = nv;
    }
    max_len = max(max_len, mx + mx2);
    return mx;
}
int main() {
    scanf("%d", &Case);
    while (Case--) {
        scanf("%d%d%d%d%d", &n, &sa, &sb, &da, &db);
        memset(fi + 1, 0, n * sizeof *fi); tot = 0;
        for (int i = 1, x, y; i < n; ++i) {
            scanf("%d%d", &x, &y);
            Add(x, y); Add(y, x);
        }
        if (db < 2 * da + 1) { puts("Alice"); continue; }
        max_len = 0;
        GetDe(sa, 0);
        if (de[sb] - de[sa] <= da) { puts("Alice"); continue; }
        puts(max_len < 2 * da + 1 ? "Alice" : "Bob");
    }
    return 0;
}