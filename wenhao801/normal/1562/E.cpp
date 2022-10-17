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

const int MAXN = 10010;
int n; char s[MAXN];

namespace SAM {
    struct node { int len, ch[26], slink; } t[MAXN];
    int top = 1, las = 1;
    vector <int> E[MAXN];

    void extend (int c) {
        int now = ++top; t[top].len = t[las].len + 1; int i, j;
        for (i = las; i && !t[i].ch[c]; i = t[i].slink) t[i].ch[c] = top;
        las = now;
        if (!i) { t[now].slink = 1; return; }
        int tmp = t[i].ch[c];
        if (t[tmp].len == t[i].len + 1) { t[now].slink = tmp; return; }
        int cl = ++top; t[cl] = t[tmp]; t[cl].len = t[i].len + 1;
        for (i; t[i].ch[c] == tmp; i = t[i].slink) t[i].ch[c] = cl;
        t[tmp].slink = t[now].slink = cl;
    }

    int fa[MAXN], siz[MAXN], dep[MAXN], wson[MAXN], tp[MAXN], id[MAXN];
    void dfs1 (int x, int f) {
        fa[x] = f, siz[x] = 1, dep[x] = dep[f] + 1, wson[x] = 0;
        for (auto v: E[x]) dfs1(v, x), siz[x] += siz[v], wson[x] = siz[v] > siz[wson[x]] ? v : wson[x];
    }
    void dfs2 (int x) {
        if (wson[x]) tp[wson[x]] = tp[x], dfs2(wson[x]);
        for (auto v: E[x]) if (v != wson[x]) tp[v] = v, dfs2(v);
    }
    int lca (int u, int v) {
        while (tp[u] != tp[v]) {
            if (dep[tp[u]] < dep[tp[v]]) swap(u, v);
            u = fa[tp[u]];
        }
        return dep[u] < dep[v] ? u : v;
    }

    void init () {
        int i, j;
        for (i = 1; i <= top; i++) {
            t[i].slink = t[i].len = 0;
            for (j = 0; j < 26; j++) t[i].ch[j] = 0;
            E[i].clear();
        }
        top = las = 1; tp[1] = 1;
        for (i = n; i >= 1; i--) extend(s[i] - 'a'), id[i] = las;
        for (i = 2; i <= top; i++) E[t[i].slink].push_back(i);
        dfs1(1, 0); dfs2(1);
    }
    
    int lcp (int u, int v) { return t[lca(id[u], id[v])].len; }
}

int f[MAXN];

int main () {
    int T = read();
    while (T--) {
        n = read(); scanf("%s", s + 1);
        SAM::init(); int i, j, ans = 0;
        for (i = 1; i <= n; i++) {
            f[i] = n - i + 1;
            for (j = 1; j < i; j++) {
                int lcp = SAM::lcp(i, j);
                if (lcp != n - i + 1 && s[i + lcp] > s[j + lcp]) f[i] = max(f[i], f[j] + n - i + 1 - lcp);
            }
            ans = max(ans, f[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}