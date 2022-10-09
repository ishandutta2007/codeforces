#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
vector<array<ll, 2>> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; v.clear(); flag[0] = 0;
        for (i = 1; i <= n; i++) {
            cin >> a; v.pb({a, i});
        }

        sort(v.begin(), v.end());
        for (i = 0; i < n; i++) {
            if ((i == 0 || v[i - 1][0] != v[i][0]) && (i == n - 1 || v[i][0] != v[i + 1][0])) {
                cout << v[i][1] << nl; flag[0] = 1; break;
            }
        }

        if (flag[0] == 0) cout << -1 << nl;
    }



    return 0;
}