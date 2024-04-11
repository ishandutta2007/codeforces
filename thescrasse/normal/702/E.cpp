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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, s;
ll f[maxn], w[maxn], jm[35][maxn], sts[35][maxn], stm[35][maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> k;
    for (i = 1; i <= n; i++) {
        cin >> f[i]; f[i]++;
    }
    for (i = 1; i <= n; i++) {
        cin >> w[i];
    }

    for (j = 1; j <= n; j++) {
        jm[0][j] = f[j];
        sts[0][j] = w[j]; stm[0][j] = w[j];
    }

    for (i = 1; i < 35; i++) {
        for (j = 1; j <= n; j++) {
            jm[i][j] = jm[i - 1][jm[i - 1][j]];
            sts[i][j] = sts[i - 1][j] + sts[i - 1][jm[i - 1][j]];
            stm[i][j] = min(stm[i - 1][j], stm[i - 1][jm[i - 1][j]]);
            // cout << i _ j _ jm[i][j] _ sts[i][j] _ stm[i][j] << nl;
        }
    }

    for (i = 1; i <= n; i++) {
        a = 0; b = INF; s = i;
        for (j = 0; j < 35; j++) {
            if ((k >> j) & 1) {
                a += sts[j][s]; b = min(b, stm[j][s]);
                s = jm[j][s];
            }
        }
        cout << a _ b << nl;
    }

    return 0;
}