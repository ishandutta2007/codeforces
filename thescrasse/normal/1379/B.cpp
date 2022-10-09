#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, l, r;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> l >> r >> m;
        for (i = l; i <= r; i++) {
            k = m % i;
            if (m >= i) {
                if (k <= r - l) {
                    cout << i << ' ' << l + k << ' ' << l << nl;
                    break;
                }
            }
            k = i - k;
            if (k <= r - l) {
                cout << i << ' ' << l << ' ' << l + k << nl;
                break;
            }
        }
    }

    return 0;
}