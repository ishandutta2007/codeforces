#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 300010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll p2[maxn], ps[maxn], df[maxn], bsl, bsm, bsu, x;
map<ll, vector<int>> adj[2];

struct rmq {
    ll st[20][maxn];

    void build() {
        ll i, j, k;
        for (i = 1; i <= 19; i++) {
            k = (1 << (i - 1));
            for (j = 1; j <= n; j++) {
                if (j + k > n) continue;
                st[i][j] = min(st[i - 1][j], st[i - 1][j + k]);
            }
        }
    }

    ll mn(ll l, ll r) {
        ll k, m;
        if (l > r) swap(l, r);
        k = p2[r - l + 1]; m = (1 << k);
        return min(st[k][l], st[k][r - m + 1]);
    }
};

rmq r0, r1;

ll cnt(ll ty, ll l, ll r, ll x) {
    return (upper_bound(adj[ty][x].begin(), adj[ty][x].end(), r) - lower_bound(adj[ty][x].begin(), adj[ty][x].end(), l));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    for (i = 2; i < maxn; i++) p2[i] = p2[i / 2] + 1;

    cin >> t;
    while (t--) {
        cin >> n; adj[0].clear(); adj[1].clear(); res = 0;
        for (i = 1; i <= n; i++) {
            cin >> a[i]; ps[i] = a[i];
            if (i >= 3) ps[i] += ps[i - 2];
            df[i] = ps[i] - ps[i - 1];
            adj[i % 2][df[i]].pb(i);
        }

        for (i = 1; i <= n; i++) {
            if (i % 2) {
                r0.st[0][i] = INF; r1.st[0][i] = df[i];
            } else {
                r0.st[0][i] = df[i]; r1.st[0][i] = INF;
            }
        }

        r0.build(); r1.build();

        /* for (i = 1; i <= n; i++) cout << df[i] << ' ';
        cout << nl; */

        for (i = 1; i <= n; i++) {
            // cout << "i =" _ i << nl;
            k = df[i - 1] * (1 - 2 * (i % 2 == 0));
            bsl = 2 * ((i + 1) / 2); bsu = n + 1;
            while (bsl != bsu) {
                bsm = (bsl + bsu) / 2;
                // cout << "mn =" _ i _ bsm _ r0.mn(i, bsm) << nl;
                if (r0.mn(i, bsm) < k) bsu = bsm;
                else bsl = bsm + 1;
            }
            x = bsl - 1;
            // cout << "bsl =" _ bsl - 1 << nl;

            k = df[i - 1] * (1 - 2 * (i % 2 == 1));
            bsl = 2 * (i / 2) + 1; bsu = n + 1;
            while (bsl != bsu) {
                bsm = (bsl + bsu) / 2;
                if (r1.mn(i, bsm) < k) bsu = bsm;
                else bsl = bsm + 1;
            }
            // cout << "bsl =" _ bsl - 1 << nl;
            x = min(x, bsl - 1);

            k = df[i - 1] * (1 - 2 * (i % 2 == 0));
            res += cnt(0, i, x, k);
            // cout << "found" _ cnt(0, i, x, k) << nl;

            k = df[i - 1] * (1 - 2 * (i % 2 == 1));
            res += cnt(1, i, x, k);
            // cout << "found" _ cnt(1, i, x, k) << nl;
        }

        cout << res << nl;
    }

    return 0;
}