#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, s, l[maxn], wu[maxn], c, tot, u, w, parent[maxn];
vector<array<ll, 2>> adj[maxn];
priority_queue<array<ll, 2>> pq;
bool visited[maxn];

void dfs(ll s) {
    ll c, u;
    l[s] = -1;
    for (auto o : adj[s]) {
        u = o[0]; c = o[1];
        if (visited[u]) continue;
        visited[u] = true;
        parent[u] = s; wu[u] = c;
        dfs(u);
        if (l[s] == -1) l[s] = 0;
        l[s] += l[u];
    }
    if (l[s] == -1) l[s] = 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> s;

        for (i = 1; i <= n; i++) {
            adj[i].clear(); visited[i] = false;
        }

        while (!pq.empty()) pq.pop();

        for (i = 0; i < n - 1; i++) {
            cin >> a >> b >> w;
            adj[a].pb({b, w}); adj[b].pb({a, w});
        }

        visited[1] = true; dfs(1);

        /* for (i = 1; i <= n; i++) cout << l[i] << ' ';
        cout << nl; */

        tot = 0;
        for (i = 2; i <= n; i++) {
            pq.push({l[i] * ((wu[i] + 1) / 2), i});
            tot += l[i] * wu[i];
        }

        res = 0;
        while (tot > s) {
            a = pq.top()[0]; b = pq.top()[1]; pq.pop();
            // cout << s << ' ' << tot << ' ' << a << ' ' << b << nl;
            tot -= a; wu[b] /= 2; res++;
            pq.push({l[b] * ((wu[b] + 1) / 2), b});
        }

        cout << res << nl;
    }

    return 0;
}