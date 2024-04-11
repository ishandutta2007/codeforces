#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 60
#define maxm 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll l[maxn], r[maxn], wy[maxm], kn[maxn][maxm];

ll solve(ll g) {
    ll i, j, lg, rg;

    // if (m % g != 0) return 0;

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m / g; j++) {
            if (i == 0) kn[i][j] = 1;
            else kn[i][j] = 0;
        }
    }

    for (i = 1; i <= n; i++) {
        lg = (l[i] + g - 1) / g; rg = r[i] / g;
        // cout << "g, lg, rg = " << g _ lg _ rg << nl;
        for (j = lg; j <= m / g; j++) {
            kn[i][j] = (kn[i][j - 1] + kn[i - 1][j - lg]) % mod;
            if (j - rg - 1 >= 0) {
                kn[i][j] = (kn[i][j] - kn[i - 1][j - rg - 1] + mod) % mod;
            }
        }
    }

    /* for (i = 0; i <= n; i++) {
        for (j = 0; j <= m / g; j++) {
            cout << kn[i][j] << ' ';
        }
        cout << nl;
    } */

    return kn[n][m / g];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }

    for (i = m; i >= 1; i--) {
        wy[i] = solve(i);
        // cout << i _ wy[i] << nl;
        for (j = 2 * i; j <= m; j += i) {
            wy[i] = (wy[i] - wy[j] + mod) % mod;
        }
    }

    cout << wy[1] << nl;

    return 0;
}