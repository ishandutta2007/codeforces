#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 400010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll x;
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
        cin >> n; v.clear(); res = 0;
        for (i = 1; i <= n; i++) {
            cin >> a[i]; v.pb({a[i], i});
        }
        a[0] = 0; a[n + 1] = 0;

        for (i = 0; i <= n; i++) res += abs(a[i] - a[i + 1]);

        sort(v.begin(), v.end()); reverse(v.begin(), v.end());

        for (auto u : v) {
            x = u[1]; k = max(a[x - 1], a[x + 1]);
            if (a[x] >= k) {
                res -= (a[x] - k); a[x] = k;
            }
        }

        cout << res << nl;
    }

    return 0;
}