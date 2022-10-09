#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 1010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll mt[maxn][maxn], q, x, y;

bool oob(ll x, ll y) {
    return (x <= 0 || x >= n + 1 || y <= 0 || y >= m + 1);
}

void upd(ll x, ll y, ll c) {
    ll ty, i, k, r = -1, a, b;
    for (ty = 0; ty <= 1; ty++) {
        k = 1; a = x; b = y;
        for (i = 1;; i++) {
            if ((i % 2) ^ ty) a--;
            else b--;
            if (oob(a, b) || mt[a][b] == 1) {
                k *= i; break;
            }
        }

        a = x; b = y;
        for (i = 1;; i++) {
            if ((i % 2) ^ ty) b++;
            else a++;
            if (oob(a, b) || mt[a][b] == 1) {
                k *= i; break;
            }
        }

        r += k;
    }

    mt[x][y] ^= 1;
    if (c == 0) res -= r;
    else res += r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m >> q;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            res++;
            res += min(2 * (n - i), 2 * (m - j) + 1);
            res += min(2 * (m - j), 2 * (n - i) + 1);
        }
    }
    /* for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            mt[i][j] = 1;
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            upd(i, j, mt[i][j]);
        }
    } */

    while (q--) {
        cin >> x >> y;
        upd(x, y, mt[x][y]);
        cout << res << nl;
    }

    return 0;
}