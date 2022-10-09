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
        cin >> n >> m; flag[0] = 0; flag[1] = 0;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                cin >> mt[i][j];
                if (mt[i][j] == '.') continue;
                flag[((i + j) % 2) ^ (mt[i][j] == 'R')] = 1;
            }
        }

        if (flag[0] + flag[1] == 2) {
            cout << "NO" << nl; continue;
        }

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                if ((flag[1]) ^ ((i + j) % 2)) mt[i][j] = 'R';
                else mt[i][j] = 'W';
            }
        }

        cout << "YES" << nl;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                cout << mt[i][j];
            }
            cout << nl;
        }
    }

    return 0;
}