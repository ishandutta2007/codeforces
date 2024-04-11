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
#define maxN 100005
#define oo 2000000007
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
    int u, v;
    bool avail;
};

int n, m, pos[maxN];
vector<int> g[maxN], odd, ord;
vector<Edge> e;
list<int> cyc;
vector<ii> ans;

void DFS(list<int>::iterator it, int u) {
//    printf("%d\n", u);
    for(; pos[u] < sz(g[u]); ++pos[u]) {
        int id = g[u][pos[u]];
        if (e[id].avail) {
            e[id].avail = false;
            int v = e[id].u+e[id].v-u;
            DFS(cyc.insert(it, u), v);
        }
    }
}

void add(int u, int v) {
    g[u].pb(sz(e)); g[v].pb(sz(e));
    e.pb({u, v, true});
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
    }

    fto(u, 1, n) {
        if (sz(g[u])%2 == 1) odd.pb(u);
    }

    for(int i = 0; i < sz(odd); i += 2) {
        add(odd[i], odd[i+1]);
    }

    if (sz(e)%2 == 1) {
        add(1, 1);
    }

    DFS(cyc.begin(), 1);
    cyc.insert(cyc.begin(), 1);

    ord.assign(cyc.begin(), cyc.end());
//    for(int u: ord) printf("%d ", u);
//    puts("");

    fto(i, 0, sz(ord)-2) {
        if (i%2 == 0) ans.pb(mp(ord[i], ord[i+1]));
        else ans.pb(mp(ord[i+1], ord[i]));
    }

    printf("%d\n", sz(ans));
    for(ii p: ans) printf("%d %d\n", p.ff, p.ss);



    return 0;
}