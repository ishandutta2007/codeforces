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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, ps[maxn], pm[maxn];

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

        pm[0] = INF; ps[1] = a[1]; pm[1] = a[1];
        for (i = 2; i <= n; i++) {
            ps[i] = ps[i - 2] + a[i]; pm[i] = min(pm[i - 2], a[i]);
        }

        res = INF;
        for (i = 2; i <= n; i++) {
            res = min(res,
            ps[i] + pm[i] * (n - (i + 1) / 2) + ps[i - 1] + pm[i - 1] * (n - i / 2));
        }

        cout << res << nl;
    }

    return 0;
}