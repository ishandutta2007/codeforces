//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
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
#define ll long long
#define maxN 200005
#define maxK 20
#define oo 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

struct edge {
    int u, v, w, c, id;
    bool inline operator < (const edge &o) const {
        return (w < o.w);
    }
};

class UFDS {
private:
    vector<int> pset;
public:
    UFDS(int n) {
        pset.resize(n+1);
        fto(i, 1, n) pset[i] = i;
    }
    int findSet(int i) {
        return (pset[i] == i) ? i : pset[i] = findSet(pset[i]);
    }
    bool isSameSet(int i, int j) {
        return (findSet(i) == findSet(j));
    }
    bool unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            pset[findSet(i)] = findSet(j);
            return true;
        }
        return false;
    }
};

int n, m, k, S, parent[maxN], pe[maxN], d[maxN], r[maxK][maxN], b[maxK][maxN];
edge e[maxN];
vector<ii> ke[maxN];
bool inST[maxN];

void DFS(int u) {
    forit(it, ke[u]) {
        int v = it->ff, w = it->ss;
        if (v != parent[u]) {
            d[v] = d[u]+1;
            parent[v] = u;
            pe[v] = w;
            DFS(v);
        }
    }
}

int maxR(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    int t = d[u]-d[v], res = 0;
    fto(i, 0, k) {
        if (t&(1<<i)) {
            res = max(res, r[i][u]);
            u = b[i][u];
        }
    }
    fdto(i, k, 0) {
        if (b[i][u] != b[i][v]) {
            res = max(res, max(r[i][u], r[i][v]));
            u = b[i][u]; v = b[i][v];
        }
    }
    if (u == v) return res;
    fto(i, 0, k) {
        if (b[i][u] == b[i][v]) return max(res, max(r[i][u], r[i][v]));
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    k = log2(n);
    fto(i, 1, m) scanf("%d", &e[i].w);
    fto(i, 1, m) scanf("%d", &e[i].c);
    fto(i, 1, m) {
        e[i].id = i;
        scanf("%d%d", &e[i].u, &e[i].v);
    }
    scanf("%d", &S);
    sort(e+1, e+m+1);
    //Spanning Tree 1
    ll wTree = 0;
    {
        int cnt = 0;
        UFDS s(n);
        fto(i, 1, m) {
            if (cnt == n-1) break;
            int u = e[i].u, v = e[i].v, w = e[i].w, id = e[i].id;
            if (s.unionSet(u, v)) {
                ++cnt;
                wTree += w;
                ke[u].pb(mp(v, w));
                ke[v].pb(mp(u, w));
                inST[id] = true;
            }
        }
    }

    DFS(1);
    fto(u, 1, n) b[0][u] = parent[u], r[0][u] = pe[u];
    fto(i, 1, k) {
        fto(u, 1, n) {
            b[i][u] = b[i-1][b[i-1][u]];
            r[i][u] = max(r[i-1][u], r[i-1][b[i-1][u]]);
        }
    }
    ll minD = (ll)oo*oo, minID = 0;
//    debug(wTree);
    fto(i, 1, m) {
        int u = e[i].u, v = e[i].v, w = e[i].w, c = e[i].c, id = e[i].id;
        ll d;
        if (!inST[id]) {
            int x = maxR(u, v);
//          printf("%d %d %d %d\n", u, v, w, c);
//          debug(x);
            d = wTree-x+w-S/c;
//          debug(d);
        }
        else d = wTree-S/c;
        if (d < minD) {
            minD = d;
            minID = i;
        }
    }

    cout << minD << endl;
    vector<ii> ans;
    ans.pb(mp(e[minID].id, e[minID].w-S/e[minID].c));
    //Spanning Tree 2
    {
        int cnt = 0;
        UFDS s(n);
        s.unionSet(e[minID].u, e[minID].v);
        fto(i, 1, m) {
            if (cnt == n-1) break;
            int u = e[i].u, v = e[i].v, w = e[i].w, id = e[i].id;
            if (s.unionSet(u, v)) {
                ++cnt;
                ans.pb(mp(id, w));
            }
        }
    }
    forit(it, ans) printf("%d %d\n", it->ff, it->ss);

    return 0;
}