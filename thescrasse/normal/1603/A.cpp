#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll dp[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    dp[0] = 1;
    for (i = 1;; i++) {
        dp[i] = ((i + 1) * dp[i - 1]) / __gcd(i + 1, dp[i - 1]);
        if (dp[i] > 1000000000) break;
    }

    cin >> t;
    while (t--) {
        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }

        flag[0] = 1;
        for (i = 1; i <= n; i++) {
            if (a[i] % dp[i] == 0) flag[0] = 0;
            if (dp[i] > 1000000000) break;
        }

        if (flag[0] == 1) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}