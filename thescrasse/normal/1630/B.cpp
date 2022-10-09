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
ll l, dn, st;
array<ll, 3> rs;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> k; st = k;
        for (i = 1; i <= n; i++) {
            cin >> a[i]; b[i] = a[i];
        }

        m = (n + k + 1) / 2; sort(b + 1, b + n + 1);

        rs = {INF, -1, -1};
        for (i = 1; i <= n - m + 1; i++) {
            rs = min(rs, {b[i + m - 1] - b[i], b[i], b[i + m - 1]});
        }

        cout << rs[1] _ rs[2] << nl;
        k = 0; l = 1; dn = 0;
        for (i = 1; i <= n; i++) {
            k -= (1 - (2 * (a[i] >= rs[1] && a[i] <= rs[2])));
            if (k >= 1 && (dn != st - 1 || i == n)) {
                cout << l _ i << nl;
                k = 0; l = i + 1; dn++;
            }
        }
    }

    return 0;
}