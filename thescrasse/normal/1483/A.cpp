#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b[maxn], f[maxn], g[maxn], x;
vector<ll> adj[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (i = 1; i <= max(n, m); i++) {
            f[i] = 0; g[i] = 0; b[i] = 0;
        }
        for (i = 1; i <= m; i++) adj[i].clear();
        for (i = 1; i <= m; i++) {
            cin >> k;
            for (j = 1; j <= k; j++) {
                cin >> a; adj[i].pb(a); f[a]++;
                if (k == 1) g[a]++;
            }
        }

        flag[0] = 1;
        for (i = 1; i <= n; i++) {
            if (g[i] > (m + 1) / 2) flag[0] = 0;
        }

        if (flag[0] == 0) {
            cout << "NO" << nl; continue;
        }

        cout << "YES" << nl;

        k = 0;
        for (i = 1; i <= n; i++) {
            if (f[i] > (m + 1) / 2) k = i;
        }

        if (k == 0) {
            for (i = 1; i <= m; i++) cout << adj[i][0] << ' ';
            cout << nl;
            continue;
        }

        x = 0;
        for (i = 1; i <= m; i++) {
            if (adj[i].size() == 1 && adj[i][0] == k) {
                b[i] = k; x++;
            }
        }

        for (i = 1; i <= m; i++) {
            if (adj[i].size() == 1) continue;
            for (auto u : adj[i]) {
                if (u == k && x + 1 <= (m + 1) / 2) {
                    b[i] = k; x++;
                }
            }
        }

        for (i = 1; i <= m; i++) {
            if (b[i] == 0) {
                for (auto u : adj[i]) {
                    if (u != k) b[i] = u;
                }
            }
        }

        for (i = 1; i <= m; i++) {
            cout << b[i] << ' ';
        }
        cout << nl;
    }

    return 0;
}