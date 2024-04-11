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

ll i, i1, j, k, k1, t, n, res, flag[10], a[maxn], b;
map<ll, ll> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; k = n; m.clear();
        for (i = 2; i * i <= n; i++) {
            while (k % i == 0) {
                k /= i; m[i]++;
            }
        }
        if (k > 1) m[k]++;

        for (i = 1; i < maxn; i++) a[i] = 1;

        res = 0;
        for (auto u : m) {
            res = max(res, u.second);
            for (i = 1; i <= u.second; i++) a[i] *= u.first;
        }

        cout << res << nl;
        for (i = res; i >= 1; i--) cout << a[i] << ' ';
        cout << nl;
    }

    return 0;
}