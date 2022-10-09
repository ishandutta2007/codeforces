#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

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
        cin >> n >> m;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cin >> mt[i][j];
            }
        }

        res = 0;
        for (i = 0; i < n; i++) {
            if (mt[i][m - 1] == 'R') res++;
        }

        for (j = 0; j < m; j++) {
            if (mt[n - 1][j] == 'D') res++;
        }

        cout << res << nl;
    }

    return 0;
}