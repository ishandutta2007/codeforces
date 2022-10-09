#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, dp[maxn];

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
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }

        m = 0;
        for (i = n; i >= 1; i--) {
            if (i + a[i] <= n) dp[i] = a[i] + dp[i + a[i]];
            else dp[i] = a[i];
            m = max(m, dp[i]);
        }

        cout << m << nl;
    }

    return 0;
}