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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, c;
char adj[maxn][maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                cin >> adj[i][j];
            }
        }

        a = -1; b = -1;

        for (i = 1; i <= n; i++) {
            for (j = i + 1; j <= n; j++) {
                if (adj[i][j] == adj[j][i]) {
                    a = i; b = j; break;
                }
            }
        }

        if (m % 2) {
            a = 1; b = 2;
        }

        if (a != -1) {
            cout << "YES" << nl;
            for (i = 1; i <= m + 1; i++) {
                if (i % 2) cout << a << ' ';
                else cout << b << ' ';
            }
            cout << nl;
            continue;
        }

        if (n == 2) {
            cout << "NO" << nl; continue;
        }

        cout << "YES" << nl;

        if (adj[1][2] == adj[2][3]) {
            a = 1; b = 2; c = 3;
        } else if (adj[2][3] == adj[3][1]) {
            a = 2; b = 3; c = 1;
        } else {
            a = 3; b = 1; c = 2;
        }

        k = m / 2 + 1;
        for (i = 1; i <= m + 1; i++) {
            if ((abs(i - k)) % 2 == 0) cout << b << ' ';
            else if (i < k) cout << a << ' ';
            else cout << c << ' ';
        }
        cout << nl;
    }

    return 0;
}