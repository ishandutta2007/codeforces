#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; s = 0;
        for (i = 0; i < n; i++) {
            cin >> a[i]; s += a[i];
        }

        sort(a, a + n);

        if (2 * a[n - 1] > s) {
            cout << "T";
        } else if (s % 2 == 0) {
            cout << "HL";
        } else {
            cout << "T";
        }
        cout << nl;
    }

    return 0;
}