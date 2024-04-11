// 1333E
// Road to 1600

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 510

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, mt[maxn][maxn], d;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    if (n <= 2) {
        cout << -1; return 0;
    }

    mt[0][0] = n * n - 3; mt[2][2] = n * n - 2;
    mt[0][2] = n * n - 1; mt[2][1] = n * n;
    i = 0; j = 1; m = n * n - 4; d = 1;
    while (true) {
        // cout << i << ' ' << j << nl;
        if (mt[i][j] == 0) {
            mt[i][j] = m; m--;
        }
        if (d == 1) {
            if (j == n - 1) {
                i++; d = 0;
            } else {
                j++;
            }
        } else {
            if (j == 0) {
                i++; d = 1;
            } else {
                j--;
            }
        }
        if (i == n) break;
    }

    swap(mt[1][1], mt[1][2]);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << mt[i][j] << ' ';
        }
        cout << nl;
    }

    return 0;
}