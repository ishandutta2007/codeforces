#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, mt[40][40], v[70][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        for (i = 0; i < 70; i++) {
            for (j = 0; j < 2; j++) {
                v[i][j] = 0;
            }
        }
        cin >> n >> m;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cin >> mt[i][j];
                v[i + j][mt[i][j]]++;
            }
        }

        res = 0;
        for (i = 0; i <= (n + m - 3) / 2; i++) {
            res += min(v[i][0] + v[n + m - i - 2][0], v[i][1] + v[n + m - i - 2][1]);
        }

        cout << res << nl;
    }

    return 0;
}