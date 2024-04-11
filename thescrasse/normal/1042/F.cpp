// 1373F
// Network Coverage

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 1000010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, dg[maxn], r, dist[maxn];
bool visited[maxn];
vector<ll> adj[maxn];
multiset<ll> sbs[maxn];

void merge(ll s) {
    while (true) {
        if (sbs[s].size() < 2) break;
        a = (*sbs[s].begin()); sbs[s].erase(sbs[s].begin());
        b = (*sbs[s].begin()); sbs[s].erase(sbs[s].begin());
        if (a + b - 2 * dist[s] <= k) {
            sbs[s].insert(b);
        } else {
            sbs[s].insert(a); sbs[s].insert(b); break;
        }
    }
}

void clean(ll s) {
    while (true) {
        if (sbs[s].size() < 2) break;
        a = (*prev(sbs[s].end())); sbs[s].erase(prev(sbs[s].end()));
        b = (*prev(sbs[s].end())); sbs[s].erase(prev(sbs[s].end()));
        if (a + b - 2 * dist[s] > k) {
            sbs[s].insert(b); res++;
        } else {
            sbs[s].insert(a); sbs[s].insert(b); break;
        }
    }
}

void dfs(ll s) {
    ll flag = 1;
    for (auto u : adj[s]) {
        if (visited[u]) continue;
        visited[u] = true; flag = 0;
        dist[u] = dist[s] + 1; dfs(u);
        if (sbs[s].size() < sbs[u].size()) swap(sbs[s], sbs[u]);
        for (auto x : sbs[u]) sbs[s].insert(x);
    }
    merge(s); clean(s);
    if (flag == 1) sbs[s].insert(dist[s]);

    /* cout << "s = " << s << nl;
    for (auto x : sbs[s]) cout << x << ' ';
    cout << nl; */
}

void init(ll s) {
    for (i = 1; i <= n; i++) visited[i] = false;
    visited[s] = true; dist[s] = 0; dfs(s);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> k;
    for (i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
        dg[a]++; dg[b]++;
    }

    for (r = 1; r <= n; r++) {
        if (dg[r] > 1) break;
    }

    res = 0; init(r);

    cout << sbs[r].size() + res;

    return 0;
}