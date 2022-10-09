#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 60

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn], x, y;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; x = INF; y = INF;
        for (i = 0; i < n; i++) {
            cin >> a[i]; x = min(x, a[i]);
        }
        for (i = 0; i < n; i++) {
            cin >> b[i]; y = min(y, b[i]);
        }

        res = 0;
        for (i = 0; i < n; i++) {
            res += max(a[i] - x, b[i] - y);
        }

        cout << res << nl;
    }

    return 0;
}