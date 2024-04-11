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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, f[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; flag[0] = 0;
        for (i = 1; i <= n; i++) f[i] = 0;
        for (i = 0; i < n; i++) {
            cin >> a[i];
            if (i != 0 && a[i] != a[i - 1]) flag[0] = 1;
            if (i != 0 && i != n - 1 && a[i] != a[i - 1]) f[a[i]]++;
            if (n != 1 && i == n - 1 && a[n - 1] == a[n - 2]) f[a[i]]--;
        }

        res = INF;
        for (i = 0; i < n; i++) {
            res = min(res, max((ll)0, f[a[i]]));
        }

        if (flag[0] == 0) cout << 0 << nl;
        else cout << res + 1 << nl;
    }

    return 0;
}