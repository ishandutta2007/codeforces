#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500005;

struct Query {
    int h, id;
};

int n, q, in[MAXN], out[MAXN], dfs_cnt, vtx[MAXN], sz[MAXN], d[MAXN], mask[MAXN];
bool ans[MAXN];
char s[MAXN];
vector<int> tree[MAXN];
vector<Query> queries[MAXN];

void getsz(int u, int par) {
    sz[u] = 1;
    vtx[dfs_cnt] = u;
    in[u] = dfs_cnt++;
    for(int v: tree[u]) {
        if (v == par) continue;
        d[v] = d[u] + 1;
        getsz(v, u);
        sz[u] += sz[v];
    }
    out[u] = dfs_cnt;
}

void add(int u) {
    mask[d[u]] ^= 1 << (s[u] - 'a');
}

void del(int u) {
    mask[d[u]] ^= 1 << (s[u] - 'a');
}

void dfs(int u, int par, bool keep) {
    int maxSz = 0, heavy = -1;
    for(int v: tree[u]) {
        if (v != par && sz[v] > maxSz) {
            maxSz = sz[v];
            heavy = v;
        }
    }

    for(int v: tree[u])
        if (v != par && v != heavy)
            dfs(v, u, 0);
    if (heavy != -1)
        dfs(heavy, u, 1);

    for(int v: tree[u])
        if (v != par && v != heavy)
            for(int i = in[v]; i < out[v]; ++i)
                add(vtx[i]);
    add(u);

//    printf("u: %d\n", u);
//    for(int h = 1; h <= n; ++h)
//        printf("%d ", mask[h]);
//    puts("");

    for(auto q: queries[u]) {
//        printf("i, h, id: %d %d %d\n", u, q.h, q.id);
        ans[q.id] = __builtin_popcount(mask[q.h]) <= 1;
    }

    if (!keep)
        for(int i = in[u]; i < out[u]; ++i)
            del(vtx[i]);
}

int main() {
    scanf("%d%d", &n, &q);
    for(int u = 1; u < n; ++u) {
        int p; scanf("%d", &p); --p;
        tree[p].push_back(u);
    }
    scanf("%s", s);
    for(int i = 0; i < q; ++i) {
        int u, h;
        scanf("%d%d", &u, &h); --u;
        queries[u].push_back({h, i});
    }

    int root = 0;
    d[root] = 1;
    getsz(root, -1);
    dfs(root, -1, 0);

    for(int i = 0; i < q; ++i)
        puts(ans[i] ? "Yes" : "No");

    return 0;
}