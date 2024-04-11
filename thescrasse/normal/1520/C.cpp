#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, x, y;
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
        cin >> n;

        if (n == 2) {
            cout << -1 << nl; continue;
        }

        k = 0;
        for (i = 1; i <= (n * n + 1) / 2; i++) {
            x = (k / n) + 1; y = (k % n) + 1;
            mt[x][y] = i; k += 2;
        }

        k = 1;
        for (i = (n * n + 3) / 2; i <= n * n; i++) {
            x = (k / n) + 1; y = (k % n) + 1;
            mt[x][y] = i; k += 2;
        }

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                cout << mt[i][j] << ' ';
            }
            cout << nl;
        }
    }

    return 0;
}