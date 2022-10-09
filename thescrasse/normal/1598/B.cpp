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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll mt[maxn][10], c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; m = 5;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                cin >> mt[i][j];
            }
        }

        flag[0] = 0;
        for (j = 1; j <= m; j++) {
            for (k = j + 1; k <= m; k++) {
                a = 0; b = 0; c = 0;
                for (i = 1; i <= n; i++) {
                    if (mt[i][j] == 1 && mt[i][k] == 0) a++;
                    if (mt[i][j] == 0 && mt[i][k] == 1) b++;
                    if (mt[i][j] == 1 && mt[i][k] == 1) c++;
                }
                if (a + b + c == n && a <= n / 2 && b <= n / 2) {
                    // cout << a _ b _ c _ j _ k << nl;
                    flag[0] = 1;
                }
            }
        }

        if (flag[0] == 1) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}