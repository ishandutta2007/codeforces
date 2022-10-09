#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll mk1, mk2;

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

        flag[0] = 0;
        for (mk1 = 0; mk1 < (1 << n); mk1++) {
            for (mk2 = 0; mk2 < (1 << n); mk2++) {
                if ((mk1 & mk2) != 0) continue;
                if (mk1 + mk2 == 0) continue;
                k = 0;
                for (i = 1; i <= n; i++) {
                    if ((mk1 >> (i - 1)) & 1) k += a[i];
                    if ((mk2 >> (i - 1)) & 1) k -= a[i];
                }
                if (k == 0) flag[0] = 1;
            }
        }

        if (flag[0] == 1) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}