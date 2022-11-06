#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int prv[maxn], nxt[maxn], fa[maxn], lt[maxn], rt[maxn], sz[maxn];

int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    fa[y] = x;
    nxt[rt[x]] = lt[y];
    prv[lt[y]] = rt[x];
    rt[x] = rt[y];
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        nxt[i] = -1;
        prv[i] = -1;
        fa[i] = i;
        lt[i] = i;
        rt[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < n - 1; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        --x, --y;
        merge(x, y);
    }
    int s = -1;
    for (int i = 0; i < n; ++i) {
        if (prv[i] == -1)
            s = i;
    }
    assert(s >= 0);
    for (int i = 0; i < n; ++i) {
        printf("%d ", s + 1);
        s = nxt[s];
    }
    puts("");
}