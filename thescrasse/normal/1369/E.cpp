// 1369E
// DeadLee

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define jn treapdidsu

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, w[maxn], r[maxn], x[maxn], y[maxn], s;
vector<ll> adj[maxn], wh[maxn], rs;
bool visited[maxn], frv[maxn];
queue<ll> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> w[i]; r[i] = 0;
    }
    for (i = 1; i <= m; i++) {
        cin >> x[i] >> y[i];
        r[x[i]]++; r[y[i]]++;
        adj[x[i]].pb(y[i]); adj[y[i]].pb(x[i]);
        wh[x[i]].pb(i); wh[y[i]].pb(i);
    }

    for (i = 1; i <= n; i++) {
        if (w[i] >= r[i]) {
            q.push(i); visited[i] = true;
        }
    }

    while (!q.empty()) {
        s = q.front(); q.pop();
        // cout << "s = " << s << nl;
        for (auto u : wh[s]) {
            if (frv[u]) continue;
            // cout << "u = " << u << nl;
            frv[u] = true;
            rs.pb(u);
        }
        for (auto u : adj[s]) {
            r[u]--;
            if (w[u] >= r[u] && visited[u] == false) {
                visited[u] = true;
                q.push(u);
            }
        }
    }

    if ((ll)rs.size() != m) {
        cout << "DEAD";
    } else {
        cout << "ALIVE" << nl;
        reverse(rs.begin(), rs.end());
        for (auto u : rs) {
            cout << u << ' ';
        }
    }

    return 0;
}