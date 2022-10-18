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
#define oo 1000000000000000007LL
#define sz(a) (int)a.size()
#define MOD 1000000009

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

int n, f[maxN], d[maxN], deg[maxN], par[maxN];
bool ok[maxN], avail[maxN];
vector<int> g[maxN];
set<ii> s;

void prep(int u) {
    if (deg[u]%2 == 0) s.insert(mp(d[u], u));
    for(int v: g[u]) {
        if (v == par[u]) continue;
        par[v] = u;
        d[v] = d[u]+1;
        prep(v);
    }
}

void DFS(int u) {
    printf("%d\n", u);
    avail[u] = false;
    s.erase(mp(d[u], u));
    for(int v: g[u]) {
        --deg[v];
        if (avail[v]) {
            if (deg[v]%2 == 0) s.insert(mp(d[v], v));
            else s.erase(mp(d[v], v));
        }
    }
    for(int v: g[u]) {
        if (!avail[v] || v == par[u]) continue;
        DFS(v);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE


    scanf("%d", &n);
    if (n%2 == 0) {
        puts("NO");
        return 0;
    }

    fto(u, 1, n) {
        int p; scanf("%d", &p);
        if (p != 0) {
            g[p].pb(u);
            g[u].pb(p);
        }
    }
    fto(u, 1, n) deg[u] = sz(g[u]);

    prep(1);

    puts("YES");
    memset(avail, true, sizeof avail);
    while (!s.empty()) {
        int u = s.rbegin()->ss;
        DFS(u);
    }

    return 0;
}