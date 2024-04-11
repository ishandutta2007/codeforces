//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 200005
#define maxB 20

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}



int n, m, k, pset[maxN], d[maxN];
ll wTree, ans[maxN];
pair<ii, ii> e[maxN];
vector<ii> ke[maxN];
vector<int> query;
ii parent[maxN], b[maxB][maxN];

int findSet(int i) {
    return (pset[i] == i) ? i : pset[i] = findSet(pset[i]);
}

void DFS(int u) {
//    debug(u);
    forit(it, ke[u]) {
        int v = it->ff, w = it->ss;
//        debug(v);
        if (v != parent[u].ff) {
            d[v] = d[u]+1;
            parent[v] = mp(u, w);
            DFS(v);
        }
    }
}

int maxEdge(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    int t = d[u]-d[v], res = 0;
    fto(i, 0, k) {
        if ((t>>i)&1) {
            res = max(res, b[i][u].ss);
            u = b[i][u].ff;
        }
    }
    fdto(i, k, 0) {
        if (b[i][u].ff != b[i][v].ff) {
            res = max(res, max(b[i][u].ss, b[i][v].ss));
            u = b[i][u].ff; v = b[i][v].ff;
        }
    }
    if (u == v) return res;
    fto(i, 0, k) {
        if (b[i][u].ff == b[i][v].ff) return max(res, max(b[i][u].ss, b[i][v].ss));
    }
}


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    k = (int)log2(n);
    fto(i, 1, m) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[i] = mp(mp(w, i), mp(u, v));
    }
    sort(e+1, e+m+1);
    fto(i, 1, n) pset[i] = i;
    fto(i, 1, m) {
        int u = e[i].ss.ff, v = e[i].ss.ss, w = e[i].ff.ff, id = e[i].ff.ss;
        int x = findSet(u), y = findSet(v);
        if (x != y) {
            pset[x] = y;
            wTree += w;
            ke[u].pb(mp(v, w));
            ke[v].pb(mp(u, w));
        }
        else query.pb(i);
    }
    fto(i, 1, m) ans[i] = wTree;
    parent[1] = mp(0, 0);
    DFS(1);

    fto(u, 1, n) b[0][u] = parent[u];
    fto(i, 1, k) {
        fto(u, 1, n) {
            b[i][u].ff = b[i-1][b[i-1][u].ff].ff;
            b[i][u].ss = max(b[i-1][u].ss, b[i-1][b[i-1][u].ff].ss);
        }
    }

    forit(it, query) {
        int u = e[*it].ss.ff, v = e[*it].ss.ss, w = e[*it].ff.ff, id = e[*it].ff.ss;
        ans[id] = wTree + w - maxEdge(u, v);
    }

    fto(i, 1, m) printf("%I64d\n", ans[i]);

    return 0;
}