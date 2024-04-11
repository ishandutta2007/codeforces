#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 300010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];

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
        for (i = 1; i <= m; i++) {
            cin >> b[i];
        }

        sort(a + 1, a + n + 1); reverse(a + 1, a + n + 1);

        k = 0;
        for (i = 1; i <= n; i++) k += b[a[i]];
        res = k;

        for (i = 1; i <= min(n, m); i++) {
            if (a[i] < i) break;
            k -= b[a[i]]; k += b[i];
            res = min(res, k);
        }

        cout << res << nl;
    }

    return 0;
}