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
#define maxN 500005
#define maxK 21
#define oo 1000000007
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

struct Query {
    vector<int> id;
    int idQ;
};

struct Edge {
    int u, v, w, id;
    bool inline operator < (const Edge &o) const {
        return w < o.w;
    }
};

struct UFDS {
    vector<int> pset;
    UFDS() {}
    void init(int n) {
        pset.assign(n+1, 0);
        fto(i, 1, n) pset[i] = i;
    }
    int findSet(int i) {return (pset[i] == i) ? i : pset[i] = findSet(pset[i]);}
    bool unionSet(int u, int v) {
        int p = findSet(u), q = findSet(v);
        if (p == q) return false;
        pset[p] = q;
        return true;
    }
};

int n, m, q, rm[maxN];
Edge e[maxN];
vector<int> g[maxN], save;
vector<Query> Q[maxN];
bool ans[maxN], visited[maxN], cycFound;
UFDS s;

void DFS(int u, int p) {
    if (cycFound) return;
    visited[u] = true;
    for(int i: g[u]) {
        int v = s.findSet(e[i].u)+s.findSet(e[i].v)-u;
//        printf("%d %d %d\n", u, v, p);
        if (v == p) {
            p = -1;
            continue;
        }
        if (visited[v]) {
            cycFound = true;
            return;
        }
        DFS(v, u);
    }
}

bool Check(const vector<int> &id) {
    for(int u: save) {
        visited[u] = false;
        g[u].clear();
    }
    save.clear();

//    for(int i: id) printf("%d ", i);
//    puts("");

    for(int i: id) {
        int u = s.findSet(e[i].u), v = s.findSet(e[i].v);
        g[u].pb(i);
        g[v].pb(i);
        save.pb(u);
        save.pb(v);
//        printf("%d %d %d %d\n", e[i].u, e[i].v, u, v);
    }

//    fto(u, 1, n) {
//        debug(u);
//        for(int id: g[u]) printf("%d ", id);
//        puts("");
//    }

    cycFound = false;
    for(int u: save) {
        if (!visited[u]) {
            DFS(u, -1);
            if (cycFound) return false;
        }
    }

//    puts("OK");
    return true;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, m) {
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
        e[i].id = i;
    }
    sort(e+1, e+m+1);
    fto(i, 1, m) rm[e[i].id] = i;

//    fto(i, 1, m) printf("%d %d %d %d\n", e[i].u, e[i].v, e[i].w, e[i].id);

    scanf("%d", &q);
    fto(iq, 1, q) {
        ans[iq] = true;

        int k; scanf("%d", &k);
        unordered_map<int, vector<int> > um;
        fto(i, 0, k-1) {
            int x; scanf("%d", &x);
            x = rm[x];
            um[e[x].w].pb(x);
        }

        forit(it, um) Q[it->ff].pb({it->ss, iq});
    }

    s.init(n);

    int i = 1;
    fto(w, 1, maxN-1) {
//        if (sz(Q[w])) debug(w);
        for(Query q: Q[w]) {
//            debug(q.idQ);
            if (!Check(q.id)) ans[q.idQ] = false;
        }

        while (i <= m && e[i].w <= w) {
            s.unionSet(e[i].u, e[i].v);
            ++i;
        }
    }

    fto(i, 1, q) puts((ans[i]) ? "YES" : "NO");


    return 0;
}