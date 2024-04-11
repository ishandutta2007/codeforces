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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;

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
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }

        j = 1; k = 0; res = -INF;
        for (i = 1; i <= n; i++) {
            while (j <= n && k <= m) {
                k += a[j]; j++;
                if (k == m) res = max(res, j - i);
            }
            // cout << i _ j _ k _ res << nl;
            k -= a[i];
        }

        if (res == -INF) res = -1;
        else res = n - res;
        cout << res << nl;
    }

    return 0;
}