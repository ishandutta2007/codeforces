#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 50010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll mt[maxn][10], x;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; m = 5;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                cin >> mt[i][j];
            }
        }

        k = 1;
        for (i = 2; i <= n; i++) {
            x = 0;
            for (j = 1; j <= m; j++) {
                if (mt[i][j] > mt[k][j]) x++;
            }

            if (x < 3) k = i;
        }

        flag[0] = 1;
        for (i = 1; i <= n; i++) {
            if (i == k) continue;
            x = 0;
            for (j = 1; j <= m; j++) {
                if (mt[i][j] > mt[k][j]) x++;
            }

            if (x < 3) flag[0] = 0;
        }

        if (flag[0] == 1) cout << k << nl;
        else cout << -1 << nl;
    }

    return 0;
}