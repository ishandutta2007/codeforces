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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll er[maxn], q, f[maxn], jm[20][maxn], l, r;
vector<ll> adj[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    for (i = 1; i < maxn; i++) er[i] = i;
    for (i = 2; i < maxn; i++) {
        if (er[i] != i) continue;
        for (j = 2 * i; j < maxn; j += i) er[j] = i;
    }

    cin >> n >> q;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (i = 1; i <= n; i++) {
        k = a[i];
        while (k != 1) {
            if (adj[er[k]].empty() || adj[er[k]].back() != i) adj[er[k]].pb(i);
            k /= er[k];
        }
    }

    f[n + 1] = n + 1;
    for (i = 1; i <= n; i++) {
        k = a[i]; f[i] = n + 1;
        while (k != 1) {
            auto it = upper_bound(adj[er[k]].begin(), adj[er[k]].end(), i);
            if (it != adj[er[k]].end()) f[i] = min(f[i], (*it));
            k /= er[k];
        }
    }
    for (i = n - 1; i >= 1; i--) {
        f[i] = min(f[i], f[i + 1]);
    }

    for (j = 1; j <= n + 1; j++) jm[0][j] = f[j];
    for (i = 1; i < 20; i++) {
        for (j = 1; j <= n + 1; j++) {
            jm[i][j] = jm[i - 1][jm[i - 1][j]];
        }
    }

    while (q--) {
        cin >> l >> r; res = 1;
        for (b = 19; b >= 0; b--) {
            if (jm[b][l] <= r) {
                l = jm[b][l]; res += (1 << b);
            }
        }

        cout << res << nl;
    }

    return 0;
}