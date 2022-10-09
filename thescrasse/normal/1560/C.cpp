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
ll sq;

ll safe_sqrt(ll x) {
    ll r = sqrt(x);
    if ((r + 1) * (r + 1) <= x) return r + 1;
    else if (r * r <= x) return r;
    else return r - 1;
}

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

        if (n == 1) {
            cout << 1 _ 1 << nl; continue;
        }

        sq = safe_sqrt(n - 1) + 1;
        n -= ((sq - 1) * (sq - 1));
        // cout << sq _ n << nl;

        if (n <= sq) cout << n _ sq << nl;
        else cout << sq _ (2 * sq - n) << nl;
    }

    return 0;
}