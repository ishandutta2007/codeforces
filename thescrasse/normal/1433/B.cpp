#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, l, r;

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
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (i = 0; i < n; i++) {
            if (a[i] == 1) {
                l = i; break;
            }
        }

        for (i = 0; i < n; i++) {
            if (a[i] == 1) r = i;
        }

        res = 0;
        for (i = l; i <= r; i++) {
            if (a[i] == 0) res++;
        }

        cout << res << nl;
    }

    return 0;
}