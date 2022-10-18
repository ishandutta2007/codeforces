#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define sz(a) (int)a.size()

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

struct Edge {
    int u, v, w;
    bool inST;
};

const int MAXN = 100025;
const int MAXM = 55;

int n, m, k, q, b[20][MAXN], h[MAXN], id[MAXN];
ll d[MAXN], c[MAXM][MAXM], c_all[MAXM][MAXN];
Edge e[MAXN];
vector<int> g[MAXN], vtx;

bool visited[MAXN];

void DFS(int u) {
    visited[u] = true;
    for(int i: g[u]) {
        int v = e[i].u + e[i].v - u, w = e[i].w;
        if (!visited[v]) {
            b[0][v] = u;
            d[v] = d[u] + w;
            h[v] = h[u] + 1;
            e[i].inST = true;
            DFS(v);
        }
    }
}

int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    int t = h[u] - h[v];
    fto(i, 0, k) {
        if ((t>>i)&1) u = b[i][u];
    }

    fdto(i, k, 0) {
        if (b[i][u] != b[i][v]) {
            u = b[i][u];
            v = b[i][v];
        }
    }

    if (u == v) return u;
    fto(i, 0, k)
        if (b[i][u] == b[i][v]) return b[i][u];
}

ll dist(int u, int v) {
    return d[u] + d[v] - 2*d[lca(u, v)];
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, m) {
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
        e[i].inST = false;
        g[e[i].u].pb(i);
        g[e[i].v].pb(i);
    }

    DFS(1);

    k = log2(n);
    fto(i, 1, k)
        fto(u, 1, n)
            b[i][u] = b[i-1][b[i-1][u]];

    fto(u, 1, n)
        id[u] = -1;

    fto(i, 1, m) {
        if (e[i].inST) continue;
        int u = e[i].u, v = e[i].v;
        if (id[u] == -1) {
            id[u] = sz(vtx);
            vtx.pb(u);
        }
        if (id[v] == -1) {
            id[v] = sz(vtx);
            vtx.pb(v);
        }
        //c[e[i].u][e[i].v] = w;
//        debug(i);
    }
//    fto(u, 1, n) printf("%d ", id[u]);
//    puts("");

    fto(u, 0, sz(vtx)-1)
        fto(v, 0, sz(vtx)-1)
            c[u][v] = dist(vtx[u], vtx[v]);

    fto(i, 1, m) {
        if (e[i].inST) continue;
        int p = id[e[i].u], q = id[e[i].v];
        c[p][q] = min(c[p][q], (ll)e[i].w);
        c[q][p] = min(c[q][p], (ll)e[i].w);
    }

    fto(k, 0, sz(vtx)-1)
        fto(u, 0, sz(vtx)-1)
            fto(v, 0, sz(vtx)-1)
                c[u][v] = min(c[u][v], c[u][k] + c[k][v]);

//    fto(u, 0, sz(vtx)-1) printf("%d ", vtx[u]);
//    puts("");
//    puts("");
//    fto(u, 0, sz(vtx)-1) {
//        fto(v, 0, sz(vtx)-1) printf("%lld ", c[u][v]);
//        puts("");
//    }

    fto(i, 0, sz(vtx)-1)
        fto(u, 1, n)
            c_all[i][u] = dist(vtx[i], u);

    scanf("%d", &q);
    fto(i, 1, q) {
        int s, t;
        scanf("%d%d", &s, &t);

        ll ans = dist(s, t);
        fto(i, 0, sz(vtx)-1) {
            int u = vtx[i];
            fto(j, 0, sz(vtx)-1) {
                int v = vtx[j];
                ans = min(ans, c_all[i][s] + c[i][j] + c_all[j][t]);
            }
        }

        printf("%lld\n", ans);
    }



    return 0;
}