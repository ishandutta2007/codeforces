#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 510

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll mt[maxn][maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; res = 0;
        for (i = 1; i <= 2 * n; i++) {
            for (j = 1; j <= 2 * n; j++) {
                cin >> mt[i][j];
                if (i > n && j > n) res += mt[i][j];
            }
        }

        res += min({mt[1][n + 1], mt[1][2 * n], mt[n][n + 1], mt[n][2 * n],
            mt[n + 1][1], mt[n + 1][n], mt[2 * n][1], mt[2 * n][n]});

        cout << res << nl;
    }

    return 0;
}