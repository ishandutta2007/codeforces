#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 1000010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, mt[3][maxn], r[3][maxn], c, mn, pc;
char x;

ll solve() {
    ll i, j, k, mn, c;
    ll res = 0;
    for (j = 1; j < m; j++) {
        mn = INF;
        for (c = 0; c <= 1; c++) {
            k = 0;
            r[0][j] = c; k += (mt[0][j] != r[0][j]);
            // cout << k << ' ';
            for (i = 1; i < n; i++) {
                r[i][j] = (r[i - 1][j - 1] ^ r[i - 1][j] ^ r[i][j - 1] ^ 1);
                k += (mt[i][j] != r[i][j]);
                // cout << k << ' ';
            }

            mn = min(mn, k);
        }

        res += mn;
    }

    // cout << nl;
    /* for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << r[i][j] << ' ';
        }
        cout << nl;
    }
    cout << res << nl; */

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m;
    if (n >= 4 && m >= 4) {
        cout << -1; return 0;
    }

    if (n == 1 || m == 1) {
        cout << 0; return 0;
    }

    if (n >= 4) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cin >> x; mt[j][i] = (ll)x - 48;
            }
        }

        swap(n, m);
    } else {
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cin >> x; mt[i][j] = (ll)x - 48;
            }
        }
    }

    /* for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << mt[i][j] << ' ';
        }
        cout << nl;
    } */

    res = INF;
    for (i = 0; i < (1 << n); i++) {
        pc = 0;
        for (j = 0; j < n; j++) {
            if ((i >> j) & 1) r[j][0] = 1;
            else r[j][0] = 0;
            pc += (r[j][0] != mt[j][0]);
        }

        k = solve();
        res = min(res, k + pc);
    }

    cout << res;

    return 0;
}