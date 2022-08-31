#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

struct Edge
{
    int v, u;
    int w;
    int id;

    Edge() : v(), u(), w(), id(-1) {}
    Edge (int _v, int _u, int _w, int _id) : v(_v), u(_u), w(_w), id(_id) {}

    bool operator < (const Edge &e) const
    {
        if (w != e.w) return w < e.w;
        return id < e.id;
    }
};

struct Query
{
    int id;
    int l, r;

    Query() : id(), l(), r() {}
    Query(int _id, int _l, int _r) : id(_id), l(_l), r(_r) {}
};

const int LOG = 30;
const int INF = (int)1e9 + 5;
const int N = 200200;
const int K = 19;
Edge ed[N];
int n, m;
bool inMST[N];
int h[N];
vector<int> g[N];
int toPar[N];
int ans[N];
int par[N];
int sz[N];
Query q[N], nq[N];
int ans2[N];
int parLCA[N][K];

int getPar(int v)
{
    return par[v] == -1 ? v : par[v] = getPar(par[v]);
}
bool unite(int v, int u)
{
    v = getPar(v);
    u = getPar(u);
    if (v == u) return false;
    if (sz[v] < sz[u]) swap(sz[v], sz[u]);
    sz[v] += sz[u];
    par[u] = v;
    return true;
}

void clearDSU()
{
    for (int i = 0; i < n; i++) {
        par[i] = -1;
        sz[i] = 1;
    }
}

void dfs(int v, int p)
{
    toPar[v] = p;
    for (int id : g[v]) {
        if (id == p) continue;
        Edge e = ed[id];
        int u = v ^ e.v ^ e.u;
        h[u] = h[v] + 1;
        parLCA[u][0] = v;
        for (int k = 0; k < K - 1; k++) {
            if (parLCA[u][k] == -1) {
                parLCA[u][k + 1] = -1;
                continue;
            }
            parLCA[u][k + 1] = parLCA[parLCA[u][k]][k];
        }
        dfs(u, id);
    }
    return;
}

int up(int v, int dh)
{
    for (int k = K - 1; k >= 0; k--) {
        if (dh < (1 << k)) continue;
        dh -= 1 << k;
        v = parLCA[v][k];
    }
    return v;
}
int LCA(int v, int u)
{
    if (h[v] > h[u]) swap(v, u);
    u = up(u, h[u] - h[v]);
    if (v == u) return v;
    for (int k = K - 1; k >= 0; k--) {
        if (parLCA[v][k] != parLCA[u][k]) {
            v = parLCA[v][k];
            u = parLCA[u][k];
        }
    }
    return parLCA[v][0];
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int v, u, w;
        scanf("%d%d%d", &v, &u, &w);
        v--;u--;
        ed[i] = Edge(v, u, w, i);
        ans[i] = INF;
    }
    sort(ed, ed + m);
    clearDSU();
    for (int i = 0; i < m; i++) {
        inMST[i] = unite(ed[i].v, ed[i].u);
    }
    int qSz = 0;
    for (int i = 0; i < m; i++) {
        if (inMST[i]) continue;
        q[qSz++] = Query(i, 0, INF);
    }
    for (int iter = 0; iter < LOG; iter++) {
        clearDSU();
        int L = 0;
        for (int i = 0; i < m && L < qSz; i++) {
            if (!inMST[i]) continue;
            while (L < qSz && ed[i].w > (q[L].l + q[L].r) / 2) {
                int R = L;
                while(R < qSz && q[L].l == q[R].l) R++;
                if (q[L].l + 1 == q[L].r) {
                    L = R;
                    continue;
                }
                int nL = L, nR = R;
                for (int j = L; j < R; j++) {
                    int v = getPar(ed[q[j].id].v), u = getPar(ed[q[j].id].u);
                    if (v == u) {
                        //cerr << "v == u" << endl;
                        nq[nL++] = Query(q[j].id, q[j].l, (q[j].l + q[j].r) / 2);
                    } else {
                        //cerr << "v != u" << endl;
                        nq[--nR] = Query(q[j].id, (q[j].l + q[j].r) / 2, q[j].r);
                    }
                }
                L = R;
            }
            if (L == qSz) break;
            if (!unite(ed[i].v, ed[i].u)) throw;
        }
        while (L < qSz) {
            int R = L;
            while(R < qSz && q[L].l == q[R].l) R++;
            if (q[L].l + 1 == q[L].r) {
                L = R;
                continue;
            }
            int nL = L, nR = R;
            for (int j = L; j < R; j++) {
                int v = getPar(ed[q[j].id].v), u = getPar(ed[q[j].id].u);
                if (v == u) {
                    //cerr << "v == u" << endl;
                    nq[nL++] = Query(q[j].id, q[j].l, (q[j].l + q[j].r) / 2);
                } else {
                    //cerr << "v != u" << endl;
                    nq[--nR] = Query(q[j].id, (q[j].l + q[j].r) / 2, q[j].r);
                }
            }
            L = R;
        }
        for (int i = 0; i < qSz; i++)
            q[i] = nq[i];
    }
    for (int i = 0; i < qSz; i++)
        ans[q[i].id] = q[i].l;

    for (int i = 0; i < m; i++) {
        if (!inMST[i]) continue;
        g[ed[i].v].push_back(i);
        g[ed[i].u].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        h[i] = -1;
        for (int k = 0; k < K; k++)
            parLCA[i][k] = -1;
    }
    h[0] = 0;
    dfs(0, -1);
    clearDSU();
    for (int i = 0; i < m; i++) {
        if (inMST[i]) continue;
        int v = ed[i].v, u = ed[i].u;
        int w = LCA(v, u);
        while(h[v] > h[w]) {
            if (par[v] != -1) {
                v = getPar(v);
                continue;
            }
            ans[toPar[v]] = ed[i].w - 1;
            par[v] = v ^ ed[toPar[v]].v ^ ed[toPar[v]].u;
            v = par[v];
        }
        v = u;
        while(h[v] > h[w]) {
            if (par[v] != -1) {
                v = getPar(v);
                continue;
            }
            ans[toPar[v]] = ed[i].w - 1;
            par[v] = v ^ ed[toPar[v]].v ^ ed[toPar[v]].u;
            v = par[v];
        }
    }

    for (int i = 0; i < m; i++) {
        ans2[ed[i].id] = (ans[i] == INF ? -1 : ans[i]);
    }
    for (int i = 0; i < m; i++)
        printf("%d ", ans2[i]);
    printf("\n");

    return 0;
}