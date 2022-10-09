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
ll st[20][maxn], p2[maxn], l, r;

ll rgq(ll l, ll r) {
    if (l > r) return 2;
    ll p = p2[r - l + 1];
    ll k = (1 << p);
    return __gcd(st[p][l], st[p][r - k + 1]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    for (i = 2; i < maxn; i++) {
        p2[i] = p2[i / 2] + 1;
    }

    cin >> t;
    while (t--) {
        cin >> n;
        for (i = 0; i <= n - 1; i++) {
            cin >> b[i];
        }

        n--;
        for (i = 1; i <= n; i++) a[i] = abs(b[i] - b[i - 1]);

        for (j = 1; j <= n; j++) st[0][j] = a[j];
        for (i = 1; i <= 19; i++) {
            for (j = 1; j <= n; j++) {
                k = (1 << (i - 1));
                if (j + k >= n + 1) continue;
                st[i][j] = __gcd(st[i - 1][j], st[i - 1][j + k]);
            }
        }

        /* for (i = 0; i <= 19; i++) {
            for (j = 1; j <= n; j++) {
                cout << st[i][j] << ' ';
            }
            cout << nl;
        } */

        l = 1; r = 0; res = 1;
        while (l <= n) {
            if (r <= n - 1 && rgq(l, r + 1) >= 2) {
                r++; res = max(res, r - l + 2);
            } else {
                l++;
            }
        }

        cout << res << nl;
    }

    return 0;
}