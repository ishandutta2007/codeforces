#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, w[maxn], f[maxn], s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        for (i = 0; i < 110; i++) f[i] = 0;

        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> w[i]; f[w[i]]++;
        }

        m = -1; res = -1;
        for (s = 0; s < 110; s++) {
            k = 0;
            for (i = 0; i <= s / 2; i++) {
                if (2 * i == s) k += f[i] / 2;
                else k += min(f[i], f[s - i]);
            }

            if (k > res) {
                res = k; m = s;
            }
        }

        cout << res << nl;
    }

    return 0;
}