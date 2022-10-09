#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], l, r;
vector<array<ll, 2>> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        s.clear();
        cin >> n; flag[0] = 0; flag[1] = 0;
        for (i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] != i + 1) {
                flag[1] = 1; a[i] = 0;
            } else {
                a[i] = 1;
            }
        }

        l = -1;
        if (a[0] == 1) l = 0;
        for (i = 1; i < n; i++) {
            if (l != -1 && a[i] == 0 && a[i - 1] == 1) {
                s.pb({l, i - 1});
            } else if (a[i] == 1 && a[i - 1] == 0) {
                l = i;
            }
        }

        for (auto u : s) {
            if (u[0] != 0 && u[1] != n - 1) flag[0] = 1;
        }

        if (flag[1] == 0) cout << 0 << nl;
        else if (flag[0] == 0) cout << 1 << nl;
        else cout << 2 << nl;
    }

    return 0;
}