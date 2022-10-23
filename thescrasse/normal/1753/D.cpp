#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    ll n, m, p, q;
    cin >> n >> m >> p >> q;
    // q = min(q, 2 * p); (is something similar needed?)

    vector<vector<char>> mt(n + 1, vector<char>(m + 1, '.'));
    vector<vector<ll>> dist(n + 1, vector<ll>(m + 1, INF));
    priority_queue<array<ll, 3>> pq;

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            cin >> mt[i][j];
            if (mt[i][j] == '.') pq.push({0, i, j}), dist[i][j] = 0;
        }
    }

    vector<vector<vector<array<ll, 3>>>> adj(n + 1, vector<vector<array<ll, 3>>>(m + 1, vector<array<ll, 3>>()));

    auto oob = [&](ll x, ll y) {
        return (x <= 0 || x > n || y <= 0 || y > m || mt[x][y] == '#');
    };

    auto ins = [&](ll a, ll b, ll c, ll d, ll e) {
        adj[a][b].pb({c, d, e});
    };

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (mt[i][j] == 'L') {
                if (!oob(i - 1, j + 1)) ins(i - 1, j + 1, i, j, p);
                if (!oob(i + 1, j + 1)) ins(i + 1, j + 1, i, j, p);
                if (!oob(i, j + 2)) ins(i, j + 2, i, j, q);
            }
            if (mt[i][j] == 'R') {
                if (!oob(i - 1, j - 1)) ins(i - 1, j - 1, i, j, p);
                if (!oob(i + 1, j - 1)) ins(i + 1, j - 1, i, j, p);
                if (!oob(i, j - 2)) ins(i, j - 2, i, j, q);
            }
            if (mt[i][j] == 'U') {
                if (!oob(i + 1, j - 1)) ins(i + 1, j - 1, i, j, p);
                if (!oob(i + 1, j + 1)) ins(i + 1, j + 1, i, j, p);
                if (!oob(i + 2, j)) ins(i + 2, j, i, j, q);
            }
            if (mt[i][j] == 'D') {
                if (!oob(i - 1, j - 1)) ins(i - 1, j - 1, i, j, p);
                if (!oob(i - 1, j + 1)) ins(i - 1, j + 1, i, j, p);
                if (!oob(i - 2, j)) ins(i - 2, j, i, j, q);
            }
        }
    }

    ll res = INF;
    while (!pq.empty()) {
        auto [d, x, y] = pq.top(); pq.pop(); d = -d;
        // cout << d _ x _ y << nl;
        if (dist[x][y] != d) continue;

        for (ll i = 0; i < 4; i++) {
            ll x1 = x + dx[i], y1 = y + dy[i];
            if (oob(x1, y1)) continue;
            res = min(res, dist[x][y] + dist[x1][y1]);
        }

        for (auto [x1, y1, w] : adj[x][y]) {
            if (dist[x1][y1] > dist[x][y] + w) {
                dist[x1][y1] = dist[x][y] + w;
                pq.push({-dist[x1][y1], x1, y1});
            }
        }
    }

    if (res == INF) cout << -1 << nl;
    else cout << res << nl;

    return 0;
}