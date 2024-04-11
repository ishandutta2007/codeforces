#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

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
        cin >> n;
        for (i = 0; i <= 100; i++) f[i] = 0;
        for (i = 0; i < n; i++) {
            cin >> a[i]; f[a[i]]++;
        }

        for (i = 1; i <= 100; i++) f[i] = min(f[i], f[i - 1]);
        flag[0] = 2; res = 0;
        for (i = 0; i <= 100; i++) {
            if (flag[0] == 2 && f[i] < 2) {
                res += i; flag[0] = 1;
            }
            if (flag[0] == 1 && f[i] < 1) {
                res += i; break;
            }
        }

        cout << res << nl;
    }

    return 0;
}