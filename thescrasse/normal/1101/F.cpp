// 1101F
// Trucks and Cities

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 410

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, c, d, l, r, p[maxn], dp[maxn][maxn], cr;
ll bsl, bsm, bsu;
vector<array<ll, 4>> tr; // s f c r

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> p[i];
    }

    for (i = 1; i <= m; i++) {
        cin >> a >> b >> c >> d;
        d = min(d, b - a - 1); tr.pb({a, b, c, d});
    }

    sort(tr.begin(), tr.end());

    for (l = 1; l <= n; l++) {
        for (r = l; r <= n; r++) {
            for (k = 0; k <= n; k++) {
                if (k >= r - l) continue;
                if (k == 0) {
                    dp[r][k] = p[r] - p[l];
                } else {
                    bsl = l; bsu = r - 1;
                    while (bsl != bsu) {
                        bsm = (bsl + bsu) / 2;
                        if (dp[bsm][k - 1] >= p[r] - p[bsm]) bsu = bsm;
                        else bsl = bsm + 1;
                    }

                    a = max(dp[bsl][k - 1], p[r] - p[bsl]); b = INF;
                    if (bsl != r) b = max(dp[bsl + 1][k - 1], p[r] - p[bsl + 1]);

                    dp[r][k] = min(a, b);
                }
            }
        }

        while (cr < m && tr[cr][0] == l) {
            res = max(res, tr[cr][2] * dp[tr[cr][1]][tr[cr][3]]); cr++;
        }
    }

    cout << res;

    return 0;
}