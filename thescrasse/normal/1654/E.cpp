#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll int
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010
#define maxa 200010
#define sq 250
#define maxs 26000010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll d, mp[maxs];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i]; a[i] += 100001;
    }

    for (d = -sq; d <= sq; d++) {
        for (i = 1; i <= n; i++) {
            k = a[i] - d * i;
            if (d > 0) k += (sq * n);
            mp[k]++; res = max(res, mp[k]);
        }
        for (i = 1; i <= n; i++) {
            k = a[i] - d * i;
            if (d > 0) k += (sq * n);
            mp[k] = 0;
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= min(n, i + maxa / sq + 2); j++) {
            if ((a[j] - a[i]) % (j - i) != 0) continue;
            k = (a[j] - a[i]) / (j - i) + maxa;
            mp[k]++; res = max(res, mp[k] + 1);
        }
        for (j = i + 1; j <= min(n, i + maxa / sq + 2); j++) {
            if ((a[j] - a[i]) % (j - i) != 0) continue;
            k = (a[j] - a[i]) / (j - i) + maxa;
            mp[k] = 0;
        }
    }

    res = n - res;
    cout << res << nl;

    return 0;
}