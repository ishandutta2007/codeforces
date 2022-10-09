#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, w[maxn], l;

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
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < k; i++) {
            cin >> w[i];
        }

        sort(a, a + n); sort(w, w + k);
        res = 0; l = 0;
        for (i = n - 1; i >= n - k; i--) {
            res += a[i];
            if (w[l] == 1) res += a[i];
            l++;
        }
        l = n - k;
        for (i = 0; i < k; i++) {
            if (w[i] != 1) {
                l -= (w[i] - 1);
                res += a[l];
            }
        }

        cout << res << nl;
    }

    return 0;
}