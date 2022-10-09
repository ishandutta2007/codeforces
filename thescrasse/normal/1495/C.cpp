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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, ns, ms;
char mt[maxn][maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> m; ns = n; ms = m;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                cin >> mt[i][j];
            }
        }
        for (i = n + 1; i % 3 != 2; i++) {
            for (j = 1; j <= m; j++) {
                mt[i][j] = '.';
            }
        }
        while (n % 3 != 1) n++;

        for (i = 1; i <= n; i += 3) {
            for (j = 1; j <= m; j++) mt[i][j] = 'X';
        }

        if (ns % 3 == 0) {
            for (j = 1; j <= m; j++) {
                if (mt[ns][j] == 'X') mt[ns - 1][j] = 'X';
            }
        }

        for (i = 2; i <= n; i += 3) {
            for (j = 1; j <= m; j++) {
                if (mt[i][j] == 'X' || mt[i + 1][j] == 'X' || j == m) {
                    mt[i][j] = 'X'; mt[i + 1][j] = 'X'; break;
                }
            }
        }

        for (i = 1; i <= ns; i++) {
            for (j = 1; j <= ms; j++) {
                cout << mt[i][j];
            }
            cout << nl;
        }
        // cout << nl;
    }

    return 0;
}