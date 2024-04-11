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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
char mt[3][maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> m; n = 2;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                cin >> mt[i][j];
            }
        }

        flag[0] = 1;
        for (j = 1; j <= m; j++) {
            if (mt[1][j] == '1' && mt[2][j] == '1') flag[0] = 0;
        }

        if (flag[0] == 1) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}