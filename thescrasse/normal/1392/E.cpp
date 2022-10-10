#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 30

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, mt[maxn][maxn], sm[maxn][maxn][2], x, q;
vector<array<ll, 2>> sl;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif */

    cin >> n;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == 0 || j == n - 1) {
                mt[i][j] = 1;
                if (i == 0) {
                    sm[i][j][0] = j + 1; sm[i][j][1] = j + 1;
                } else {
                    sm[i][j][0] = n + i; sm[i][j][1] = sm[i][j - 1][1] + 1;
                }
            } else {
                sm[i][j][0] = sm[i - 1][j + 1][1] + 1;
                mt[i][j] = sm[i][j][0] - sm[i - 1][j][0];
                if (j > 0) sm[i][j][1] = sm[i][j - 1][1] + mt[i][j];
                else sm[i][j][1] = sm[i - 1][j][1] + mt[i][j];
                // cout << sm[i][j][1] << ' ' << sm[i - 1][j][1] << ' ' << mt[i][j] << nl;
            }

            // cout << i << ' ' << j << ' ' << sm[i][j][0] << ' ' << mt[i][j] << ' ' << sm[i][j][1] << nl;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << mt[i][j] << ' ';
        }
        cout << nl;
    }
    cout << flush;

    /* for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << sm[i][j][0] << ' ';
        }
        cout << nl;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << sm[i][j][1] << ' ';
        }
        cout << nl;
    }
    cout << flush; */

    cin >> q;
    while (q--) {
        cin >> x; sl.clear();
        i = n - 1; j = n - 1;
        while (i + j != 0) {
            x -= mt[i][j];
            if (i > 0) {
                if (x >= sm[i - 1][j][0] && x <= sm[i - 1][j][1]) i--;
                else j--;
            } else {
                j--;
            }
            sl.pb({i, j});
        }

        reverse(sl.begin(), sl.end());
        for (auto u : sl) {
            cout << u[0] + 1 << ' ' << u[1] + 1 << nl;
        }
        cout << n << ' ' << n << nf;
    }

    return 0;
}