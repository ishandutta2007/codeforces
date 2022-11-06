#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
map<int, int> ds;
int fa[maxn], wf[maxn];

int gi(int x) {
    if (ds.find(x) != ds.end()) return ds[x];
    int t = ds.size();
    ds[x] = t;
    return t;
}

void init() {
    for (int i = 0; i < maxn; ++i) {
        fa[i] = i;
        wf[i] = 0;
    }
}

int find(int x) {
    if (x == fa[x]) return x;
    int f = fa[x];
    int res = find(fa[x]);
    wf[x] ^= wf[f];
    return fa[x] = res;
}

void merge(int x, int y, int w) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    fa[fx] = fy;
    wf[fx] = (wf[y] ^ wf[x] ^ w);
}

// s[y] ^ s[fy] = w[y]
// s[x] ^ s[fx] = w[x]
// s[x] ^ s[y] = w
// s[fx] ^ s[fy] = s[fx] ^ s[x] ^ s[y] ^ s[fy] ^ w = w[y] ^ w[x] ^ w

int main() {
    int q; scanf("%d", &q);
    int last = 0;
    init();
    gi(0);
    while (q--) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int l, r, x; scanf("%d%d%d", &l, &r, &x);
            l ^= last, r ^= last, x ^= last;
            if (l > r) swap(l, r);
            ++l, ++r;
            l = gi(l - 1), r = gi(r);
            if (find(l) == find(r) && (wf[l] ^ wf[r]) != x) continue;
            merge(l, r, x);
        } else {
            int l, r; scanf("%d%d", &l, &r);
            l ^= last, r ^= last;
            if (l > r) swap(l, r);
            ++l, ++r;
            if (ds.find(l - 1) == ds.end() || ds.find(r) == ds.end()) {
                last = 1;
                puts("-1");
                continue;
            }
            l = gi(l - 1), r = gi(r);
            if (find(l) != find(r)) {
                last = 1;
                puts("-1");
                continue;
            }
            printf("%d\n", (last = (wf[l] ^ wf[r])));
        }
    }
    return 0;
}