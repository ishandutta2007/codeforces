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
#define maxK 20
#define MOD 1000000007
#define oo 1000000007
#define sz(a) (int)a.size()
#define EPS 1e-9

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

int n, q, k, dfsCnt, d[maxN], in[maxN], par[maxN], b[maxK][maxN], dp[maxN], ans;
bool marked[maxN];
vector<int> g[maxN], h[maxN];
vector<ii> vtx;

void DFS(int u) {
    in[u] = ++dfsCnt;
    for(int v: g[u]) {
        if (v == par[u]) continue;
        par[v] = u;
        d[v] = d[u]+1;
        DFS(v);
    }
}

int LCA(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    int t = d[u]-d[v];
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

void Solve(int u) {
    int sum = 0;
    bool childMarked = false;
    for(int v: h[u]) {
        if (par[v] == u && marked[v]) childMarked = true;
        Solve(v);
        sum += dp[v];
    }
//    printf("%d %d\n", u, sum);
    if (marked[u]) {
        if (childMarked) ans = -oo;
        else {
            ans += sum;
            dp[u] = 1;
        }
    } else {
        if (sum > 1) ++ans;
        dp[u] = (sum == 1);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].pb(v); g[v].pb(u);
    }

    DFS(1);

    k = log2(n);
    fto(u, 1, n) b[0][u] = par[u];
    fto(i, 1, k) {
        fto(u, 1, n) b[i][u] = b[i-1][b[i-1][u]];
    }

//    fto(u, 1, n) printf("%d %d\n", par[u], d[u]);

    scanf("%d", &q);
    fto(iq, 1, q) {
//        debug(iq);
        int k; scanf("%d", &k);
        fto(i, 1, k) {
            int u; scanf("%d", &u);
            marked[u] = true;
            vtx.pb(mp(in[u], u));
        }
        sort(vtx.begin(), vtx.end());

        fto(i, 0, k-2) {
            int u = LCA(vtx[i].ss, vtx[i+1].ss);
//            printf("%d %d %d\n", vtx[i].ss, vtx[i+1].ss, u);
            vtx.pb(mp(in[u], u));
        }
        sort(vtx.begin(), vtx.end());
        vtx.resize(unique(vtx.begin(), vtx.end())-vtx.begin());
//        for(ii p: vtx) printf("%d %d\n", p.ff, p.ss);

        int root = vtx[0].ss;

        stack<int> s;
        s.push(root);
        fto(i, 1, sz(vtx)-1) {
            int u = vtx[i].ss;
            while (LCA(u, s.top()) != s.top()) s.pop();
            h[s.top()].pb(u);
//            printf("%d %d\n", s.top(), u);
            s.push(u);
        }

        ans = 0;
        Solve(root);
        if (ans < 0) ans = -1;
        printf("%d\n", ans);

        fto(i, 0, sz(vtx)-1) {
            int u = vtx[i].ss;
            marked[u] = false;
            h[u].clear();
        }
        vtx.clear();
    }

    return 0;
}