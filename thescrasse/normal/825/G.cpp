// 825G
// Tree Queries

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (int)1e9
#define mod 1000000007
#define maxn 1000010

int i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
int parent[maxn], jm[20][maxn], ty, x, last, lca_c;
int jm_m[20][maxn], dist[maxn], q;
bool vis[maxn], mzd[maxn];
vector<int> adj[maxn];

void dfs(int s) {
    for (auto u : adj[s]) {
        if (vis[u]) continue;
        vis[u] = true;
        parent[u] = s; dist[u] = dist[s] + 1;
        jm[0][u] = parent[u]; jm_m[0][u] = parent[u];
        for (i = 1; (1 << i) <= dist[u]; i++) {
            jm[i][u] = jm[i - 1][jm[i - 1][u]];
            jm_m[i][u] = min(jm_m[i - 1][u], jm_m[i - 1][jm[i - 1][u]]);
        }
        dfs(u);
    }
}

array<int, 2> kth(int s, int k) {
    int bt, m = s;
    for (bt = 0; bt <= 20; bt++) {
        if ((k >> bt) & 1) {
            m = min(m, jm_m[bt][s]);
            s = jm[bt][s];
        }
    }
    return {s, m};
}

array<int, 2> lca(int a, int b) {
    // cout << "lca " << a _ b << nl;

    int bt, m;
    m = min(a, b);
    if (dist[a] < dist[b]) swap(a, b);
    array<int, 2> o = kth(a, dist[a] - dist[b]);
    a = o[0]; m = min(m, o[1]);
    if (a == b) {
        // cout << a _ m << nl;
        return {a, m};
    }

    for (bt = 19; bt >= 0; bt--) {
        if (jm[bt][a] != jm[bt][b]) {
            m = min({m, jm_m[bt][a], jm_m[bt][b]});
            a = jm[bt][a]; b = jm[bt][b];
        }
    }

    m = min(m, parent[a]);
    // cout << parent[a] _ m << nl;
    return {parent[a], m};
}

void init(int s) {
    int i;
    for (i = 1; i <= n; i++) vis[i] = false;
    vis[s] = true; dfs(s);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> q;
    for (i = 1; i <= n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }

    init(1);

    m = INF;
    while (q--) {
        cin >> ty >> x;
        x = (x + last) % n + 1;
        if (ty == 1) {
            if (lca_c == 0) lca_c = x;
            else lca_c = lca(lca_c, x)[0];
            mzd[x] = true; m = min(m, x);
            while (true) {
                if (x == lca_c) break;
                x = parent[x];
                if (x == 0 || mzd[x]) break;
                mzd[x] = true; m = min(m, x);
            }
        } else {
            res = min(m, lca(lca_c, x)[1]);
            last = res;
            cout << res << nl;
        }
    }

    return 0;
}