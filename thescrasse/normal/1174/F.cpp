// 1174F
// Ehab and the Big Finale

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 1000000007
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, sb[maxn], mx[maxn][2], s, d, dist[maxn], parent[maxn];
vector<ll> adj[maxn];
bool visited[maxn];

ll ask(char c, ll x) {
    ll r;
    cout << c << ' ' << x << nf;
    if (c == '!') exit(0);
    cin >> r;
    if (r == -1) exit(0);
    return r;
}

void dfs(ll s) {
    sb[s] = (dist[s] == d); mx[s][0] = -1;
    for (auto u : adj[s]) {
        if (visited[u]) continue;
        visited[u] = true;
        parent[u] = s; dist[u] = dist[s] + 1;
        dfs(u);
        sb[s] += sb[u];
        if (sb[u] > mx[s][0]) {
            mx[s][0] = sb[u]; mx[s][1] = u;
        }
    }
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

    cin >> n;
    for (i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }

    d = ask('d', 1);

    init(1);

    s = 1;
    while (true) {
        while (true) {
            if (dist[s] == d) break;
            s = mx[s][1];
        }
        k = ask('d', s); k /= 2;
        if (k == 0) ask('!', s);
        while (k--) s = parent[s];
        s = ask('s', s);
    }

    return 0;
}