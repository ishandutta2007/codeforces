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
        cin >> n >> k; flag[0] = 0;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == k) flag[0] = 1;
        }

        sort(a + 1, a + n + 1);
        for (i = 2; i <= n; i++) a[i] -= a[1];
        k -= a[1]; a[1] = 0; m = a[2];
        for (i = 3; i <= n; i++) m = __gcd(m, a[i]);

        if (k % m == 0) cout << "YES" << nl;
        else if (flag[0] == 1) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}