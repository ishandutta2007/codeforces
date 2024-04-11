// 1363E
// Tree Shuffling

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18
#define maxn 200010
#define pb push_back

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, c, ty[maxn], u, v, rem[maxn][2];
vector<ll> adj[maxn];
bool visited[maxn];

void dfs(ll s) {
    // cout << s << endl;
    ll i, j, k;
    rem[s][0] = 0; rem[s][1] = 0;
    if (ty[s] >= 1) rem[s][ty[s] - 1]++;
    for (auto u : adj[s]) {
        if (!visited[u]) {
            visited[u] = true;
            a[u] = min(a[s], a[u]);
            dfs(u);
            for (i = 0; i < 2; i++) {
                rem[s][i] += rem[u][i];
            }
        }
    }

    // cout << rem[s][0] << ' ' << rem[s][1] << endl;
    k = min(rem[s][0], rem[s][1]);
    res += k * a[s];
    rem[s][0] -= k; rem[s][1] -= k;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i] >> b >> c;
        if (b == 1 && c == 0) ty[i] = 1;
        else if (b == 0 && c == 1) ty[i] = 2;
        else ty[i] = 0;
    }
    for (i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }

    res = 0; visited[1] = true; dfs(1);
    res *= 2;

    if (rem[1][0] == rem[1][1]) cout << res;
    else cout << -1;

    return 0;
}