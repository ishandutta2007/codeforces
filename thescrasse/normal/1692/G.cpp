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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];
ll ps[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (i = 1; i <= n; i++) {
            cin >> a[i]; b[i] = (2 * a[i] <= a[i - 1]);
            ps[i] = ps[i - 1] + b[i];
        }

        /* for (i = 1; i <= n; i++) cout << ps[i] << ' ';
        cout << nl; */

        res = 0;
        for (i = k + 1; i <= n; i++) {
            if (ps[i] == ps[i - k]) res++;
        }

        cout << res << nl;
    }

    return 0;
}