#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
bool visited[maxn];
vector<ll> adj[maxn];

void dfs(ll s) {
    if (visited[s]) return;
    visited[s] = true;
    for (auto u : adj[s]) dfs(u);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m;
    for (i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }

    res = 1;
    for (i = 1; i <= n; i++) {
        res *= 2;
        if (!visited[i]) {
            dfs(i); res /= 2;
        }
    }

    cout << res;

    return 0;
}