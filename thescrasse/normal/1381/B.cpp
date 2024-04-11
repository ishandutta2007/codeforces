#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF 1e9
#define mod 998244353
#define maxn 4010

int i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, bp[maxn];
int ps[maxn][2010][2];

array<int, 2> dc(int x) {
    return {x % 10000, x / 10000};
}

ll nc(int a, int b) {
    return 10000 * b + a;
}

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
        for (i = 1; i <= 2 * n; i++) {
            cin >> a[i];
        }

        for (i = 2; i <= 2 * n; i++) {
            bp[i] = 0;
            for (j = i - 1; j >= 1; j--) {
                if (a[j] > a[i]) {
                    bp[i] = j; break;
                }
            }
        }

        for (i = 0; i <= 2 * n; i++) {
            for (j = 0; j <= n; j++) {
                for (k = 0; k < 2; k++) {
                    ps[i][j][k] = -1;
                }
            }
        }

        ps[1][1][1] = 1;
        for (i = 1; i < 2 * n; i++) {
            for (j = 0; j <= n; j++) {
                ps[i + 1][j][0] = max(ps[i + 1][j][0], ps[i][j][0]);
                if (bp[i + 1] < ps[i][j][0] && j < n) {
                    ps[i + 1][j + 1][1] = max(ps[i + 1][j + 1][1], i + 1);
                }

                if (j < n) {
                    ps[i + 1][j + 1][1] = max(ps[i + 1][j + 1][1], ps[i][j][1]);
                }
                if (bp[i + 1] < ps[i][j][1]) {
                    ps[i + 1][j][0] = max(ps[i + 1][j][0], i + 1);
                }
            }
        }

        /* for (i = 0; i <= 2 * n; i++) {
            for (j = 0; j <= n; j++) {
                cout << ps[i][j][0] << ' ';
            }
            cout << nl;
        }

        for (i = 0; i <= 2 * n; i++) {
            for (j = 0; j <= n; j++) {
                cout << ps[i][j][1] << ' ';
            }
            cout << nl;
        } */

        if (ps[2 * n][n][0] != -1 || ps[2 * n][n][1] != -1) {
            cout << "YES" << nl;
        } else {
            cout << "NO" << nl;
        }
    }

    return 0;
}