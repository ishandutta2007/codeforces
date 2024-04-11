#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], b;
ll x, y;
vector<ll> a;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; a.clear(); a.resize(n + 1);
        a[0] = -INF;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }

        res = 0;
        for (i = 1; i <= n; i++) {
            if (i != n && a[i] == a[i + 1]) continue;

            j = i; k = 1;
            while (a[j] == a[j - 1]) {
                k++; j--;
            }

            j = i; x = a[j]; y = a[j];
            while (true) {
                auto it = lower_bound(a.begin(), a.end(), 2 * y - x + (y == a[i]));
                if (it == a.end()) break;
                j = it - a.begin(); y = a[j]; k++;
            }
            res = max(res, k);
        }

        res = n - res;
        cout << res << nl;
    }

    return 0;
}