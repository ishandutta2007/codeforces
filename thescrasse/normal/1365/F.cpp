#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 510

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];
vector<array<ll, 2>> v1, v2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        v1.clear(); v2.clear();

        cin >> n;
        for (i = 0; i < n; i++) cin >> a[i];
        for (i = 0; i < n; i++) cin >> b[i];

        if (n % 2 == 1) {
            if (a[n / 2] != b[n / 2]) {
                cout << "No" << nl;
                continue;
            }
        }

        for (i = 0; i < n / 2; i++) {
            v1.pb({a[i], a[n - i - 1]});
            if (v1[i][0] > v1[i][1]) swap(v1[i][0], v1[i][1]);
        }

        for (i = 0; i < n / 2; i++) {
            v2.pb({b[i], b[n - i - 1]});
            if (v2[i][0] > v2[i][1]) swap(v2[i][0], v2[i][1]);
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        /* for (auto u : v1) {
            cout << u[0] << ' ' << u[1] << nl;
        }

        for (auto u : v2) {
            cout << u[0] << ' ' << u[1] << nl;
        } */

        flag[0] = 0;
        for (i = 0; i < n / 2; i++) {
            if (v1[i] != v2[i]) flag[0] = 1;
        }

        if (flag[0] == 0) cout << "Yes" << nl;
        else cout << "No" << nl;
    }

    return 0;
}