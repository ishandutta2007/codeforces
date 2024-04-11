#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb emplace_back
#define _ << ' ' <<

#define INF (ll)1000000000000000000
#define mod 998244353
#define maxn 200010

int i, i1, j, k, k1, tc, n, m, flag[10], a, b;
int w, ty, z, q;
ll dist[maxn], cr[maxn], res;
array<int, 4> el[maxn];
vector<int> adj[maxn];

void dij() {
    int i;
    priority_queue<array<ll, 2>> pq;
    for (i = 1; i <= n; i++) dist[i] = INF;
    dist[1] = 0; pq.push({0, 1});
    while (!pq.empty()) {
        auto [d, s] = pq.top(); pq.pop(); d = -d;
        if (dist[s] != d) continue;
        for (auto o : adj[s]) {
            auto [t, u, st, w] = el[o];
            if (u == s) swap(t, u);
            if (dist[u] <= dist[s] + w) continue;
            dist[u] = (ll)dist[s] + w; pq.push({-dist[u], u});
        }
    }
    for (i = 1; i <= n; i++) dist[i] = min(INF, dist[i]);
    for (i = 1; i <= n; i++) cr[i] += dist[i];
    if (cr[i] > INF) cr[i] = INF;
}

void bfs(ll ln) {
    int i, s;
    vector<int> vv[ln];
    for (i = 1; i <= n; i++) dist[i] = INF;
    dist[1] = 0; vv[0].pb(1);

    // for (i = 1; i <= m; i++) cout << el[i][0] _ el[i][1] _ el[i][2] _ el[i][3] << nf;

    for (i = 0; i < ln; i++) {
        while (!vv[i].empty()) {
            s = vv[i].back(); vv[i].pop_back();
            if (dist[s] != i) continue;
            // cout << "i, s =" _ i _ s << nl;
            for (auto o : adj[s]) {
                auto [t, u, st, w] = el[o];
                if (u == s) swap(t, u);
                if (dist[u] <= dist[s] + w) continue;
                // cout << "o, u, w =" _ o _ u _ w << nf;
                // assert(w >= 0);
                dist[u] = (ll)dist[s] + w;
                if (dist[u] < ln) vv[dist[u]].pb(u);
            }
        }
    }
    for (i = 1; i <= n; i++) {
        dist[i] = min(INF, dist[i]); cr[i] = min(INF, cr[i]);
    }
    for (i = 1; i <= n; i++) cr[i] += dist[i];
    if (cr[i] > INF) cr[i] = INF;

    /* for (i = 1; i <= n; i++) cout << cr[i] << ' ';
    cout << nf; */
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m >> q;
    for (i = 1; i <= m; i++) {
        cin >> a >> b >> w; el[i] = {a, b, w, w};
        adj[a].pb(i);
    }

    dij();
    while (q--) {
        cin >> ty;
        if (ty == 1) {
            cin >> a; res = cr[a];
            if (res >= INF) res = -1;
            cout << res << nl;
        } else {
            cin >> z;
            for (i = 1; i <= z; i++) {
                cin >> a; el[a][2]++;
            }
            for (i = 1; i <= m; i++) el[i][3] = min(INF, el[i][2] - (cr[el[i][1]] - cr[el[i][0]]));
            bfs(z + 1);
        }
    }

    return 0;
}