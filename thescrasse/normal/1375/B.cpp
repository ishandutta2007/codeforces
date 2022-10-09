#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 310

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, mt[maxn][maxn];

ll vl(ll a, ll b) {
    ll r = 4;
    if (a == 0) r--;
    if (a == n - 1) r--;
    if (b == 0) r--;
    if (b == m - 1) r--;
    return r;
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
        cin >> n >> m; flag[0] = 1;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cin >> mt[i][j];
                if (mt[i][j] > vl(i, j)) flag[0] = 0;
            }
        }

        if (flag[0] == 0) {
            cout << "NO" << nl;
        } else {
            cout << "YES" << nl;
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    cout << vl(i, j) << ' ';
                }
                cout << nl;
            }
        }
    }

    return 0;
}