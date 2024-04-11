//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define maxN 200005
#define MOD 1000
#define oo 1000000000000000007LL

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

struct Graph {
    vector<vector<int> > g;
    vector<int> num, low, scc;
    stack<int> s;
    int n, dfsCnt = 0, sccCnt = 0;

    Graph(int n): n(n) {
        g.assign(n+1, vector<int>());
        num.assign(n+1, 0);
        low.assign(n+1, 0);
        scc.assign(n+1, 0);
    }

    void dfs(int u, int p) {
        s.push(u);
        low[u] = num[u] = ++dfsCnt;
        for(int v: g[u]) {
            if (scc[v]) continue;
            if (v == p) {
                p = -1;
                continue;
            }
            if (!num[v]) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
            } else low[u] = min(low[u], num[v]);
        }

        if (low[u] == num[u]) {
            ++sccCnt;
            int v;
            do {
                v = s.top();
                scc[v] = sccCnt;
                s.pop();
            } while (v != u);
        }
    }

    void addEdge(int u, int v) {
        g[u].pb(v); g[v].pb(u);
    }

    vector<vector<int> > getSCCTree() {
        fto(u, 1, n)
            if (!scc[u]) dfs(1, -1);
        vector<vector<int> > t(sccCnt+1, vector<int>());
        fto(u, 1, n) {
            for(int v: g[u]) {
                if (scc[u] != scc[v]) t[scc[u]].pb(scc[v]);
            }
        }
        return t;
    }
};

int n, m, q, dfsCnt, colCnt, col[maxN], par[maxN], in[maxN], d[maxN], sz[maxN], best[maxN], nxt[maxN];
vector<vector<int> > g2;
set<int> s[3];

void dfs_sz(int u) {
    col[u] = colCnt;
    sz[u] = 1;
    best[u] = -1;
    for(int v: g2[u]) {
        if (v == par[u]) continue;
        par[v] = u;
        d[v] = d[u]+1;
        dfs_sz(v);
        if (best[u] == -1 || sz[v] > sz[best[u]])
            best[u] = v;
    }
}

void dfs_hld(int u) {
    in[u] = ++dfsCnt;
    for(int v: g2[u]) {
        if (v == par[u]) continue;
        nxt[v] = (v == best[u]) ? nxt[u] : v;
        dfs_hld(v);
    }
}

void changeDir(int &u, int &v, int &dir) {
    swap(u, v);
    dir = 3-dir;
}

void update(int l, int r, int val) {
//    printf("update: %d %d %d\n", l, r, val);
    int i = *s[3-val].lower_bound(l);
    if (i <= r) {
        puts("No");
        exit(0);
    }
    while (true) {
        i = *s[0].lower_bound(l);
        if (i > r) break;
        s[0].erase(i);
        s[val].insert(i);
    }
}

void go(int u, int v, int dir) {
//    printf("go: %d %d %d\n", u, v, dir);
    if (nxt[u] == nxt[v]) {
        if (d[u] > d[v]) changeDir(u, v, dir);
        if (u != v) update(in[best[u]], in[v], dir);
        return;
    }
    if (d[nxt[u]] < d[nxt[v]]) changeDir(u, v, dir);
    update(in[nxt[u]], in[u], 3-dir);
    go(par[nxt[u]], v, dir);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &q);
    Graph g1(n);

    fto(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        g1.addEdge(u, v);
    }

    g2 = g1.getSCCTree();
//    fto(u, 1, n) printf("%d ", g1.scc[u]);
//    puts("");
    n = g2.size()-1;

//    fto(u, 1, n) {
//        debug(u);
//        for(int v: g2[u]) printf("%d ", v);
//        puts("");
//    }
    fto(u, 1, n) {
        if (par[u] == 0) {
            nxt[u] = u;
            ++colCnt;
            dfs_sz(u);
            dfs_hld(u);
        }
    }
//    fto(u, 1, n) printf("%d %d %d\n", in[u], best[u], nxt[u]);
//    puts("");

    fto(u, 1, n) s[0].insert(in[u]);
    fto(i, 0, 2) s[i].insert(n+1);

    fto(i, 1, q) {
        int u, v;
        scanf("%d%d", &u, &v);
        u = g1.scc[u]; v = g1.scc[v];
        if (col[u] != col[v]) {
            puts("No");
            return 0;
        }
        go(u, v, 1);
    }

    puts("Yes");

    return 0;
}