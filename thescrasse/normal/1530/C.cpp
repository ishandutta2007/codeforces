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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];
ll sa[maxn], sb[maxn], ta, tb;

ll calc(ll x) {
    return (x - (x / 4));
}

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
        for (i = 1; i <= n; i++) {
            cin >> b[i];
        }

        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);

        sa[n + 1] = 0; sb[n + 1] = 0;
        for (i = n; i >= 1; i--) {
            sa[i] = sa[i + 1] + a[i]; sb[i] = sb[i + 1] + b[i];
        }

        for (i = 0; i <= 3 * n; i++) {
            k = calc(n + i);

            ta = 100 * i;
            if (k - i >= 1) ta += sa[n - (k - i) + 1];

            if (k <= n) tb = sb[n - k + 1];
            else tb = sb[1];

            if (ta >= tb) {
                cout << i << nl; break;
            }
        }
    }

    return 0;
}