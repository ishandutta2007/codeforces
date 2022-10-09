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
        cin >> n; res = 0;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) b[j] = a[j];

            for (j = 1; j <= n; j++) {
                if (j == i) continue;
                while (b[j] % 2 == 0) {
                    b[j] /= 2; b[i] *= 2;
                }
            }

            k = 0;
            for (j = 1; j <= n; j++) k += b[j];
            res = max(res, k);
        }

        cout << res << nl;
    }

    return 0;
}