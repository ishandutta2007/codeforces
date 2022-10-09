#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, dp[maxn], sm[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; res = 0;
        for (i = 0; i < n; i++) {
            cin >> a[i];
            if (i != 0) {
                if (a[i] < a[i - 1]) res += (a[i - 1] - a[i]);
            }
        }

        cout << res << nl;
    }

    return 0;
}