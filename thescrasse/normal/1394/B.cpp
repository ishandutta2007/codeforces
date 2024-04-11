// 1394B
// Boboniu Walks on Graph

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, w, f[10][10], pm[10], dv[10], o;
vector<array<ll, 4>> adj[maxn];
vector<array<ll, 2>> rdt[maxn];
array<ll, 2> x;
bool fb[10][10][10][10];
vector<ll> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m >> o;
    for (i = 0; i < m; i++) {
        cin >> a >> b >> w;
        adj[a].pb({b, w, -1, -1});
    }

    for (i = 0; i <= o; i++) {
        for (j = 0; j <= o; j++) {
            f[i][j] = 0;
        }
    }

    for (i = 1; i <= n; i++) {
        v.clear();
        for (auto u : adj[i]) v.pb(u[1]);
        sort(v.begin(), v.end());
        k = v.size();
        for (j = 0; j < k; j++) {
            for (auto &u : adj[i]) {
                if (v[j] == u[1]) {
                    u[2] = k; u[3] = j + 1;
                }
            }
        }
    }

    for (i = 1; i <= n; i++) {
        for (auto u : adj[i]) {
            b = u[0]; rdt[b].pb({u[2], u[3]});
        }
    }

    for (i = 1; i <= n; i++) {
        // cout << "i = " << i << nl;
        sort(rdt[i].begin(), rdt[i].end());
        rdt[i].resize(unique(rdt[i].begin(), rdt[i].end()) - rdt[i].begin());
        for (auto u : rdt[i]) {
            f[u[0]][u[1]]++;
            // cout << u[0] << ' ' << u[1] << nl;
            for (auto v : rdt[i]) {
                fb[u[0]][u[1]][v[0]][v[1]] = true;
            }
        }
    }

    for (i = 1; i <= o; i++) {
        pm[i] = i;
    }

    res = 0;
    do {
        for (i = o; i >= 1; i--) {
            k = 0;
            for (j = 1; j <= o; j++) {
                if (pm[j] == i) dv[i] = k + 1;
                else if (pm[j] < i) k++;
            }
        }

        /* for (i = 1; i <= o; i++) cout << pm[i] << ' ';
        cout << nl;
        for (i = 1; i <= o; i++) cout << dv[i] << ' ';
        cout << nl; */

        k = 0; flag[0] = 1;
        for (i = 1; i <= o; i++) {
            k += f[i][dv[i]];
            for (j = i + 1; j <= o; j++) {
                if (fb[i][dv[i]][j][dv[j]] == true) flag[0] = 0;
            }
        }

        if (k == n && flag[0] == 1) res++;
        // cout << k << ' ' << flag[0] << nl;
    } while (next_permutation(pm + 1, pm + o + 1));

    cout << res;

    return 0;
}