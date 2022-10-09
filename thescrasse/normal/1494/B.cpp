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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, u, d, l, r;

bool solve(ll x, ll u, ll d, ll l, ll r) {
    if (x & 1) {
        u--; l--;
    }
    if (x & 2) {
        u--; r--;
    }
    if (x & 4) {
        d--; l--;
    }
    if (x & 8) {
        d--; r--;
    }
    if (u < 0 || u > n - 2) return false;
    if (d < 0 || d > n - 2) return false;
    if (l < 0 || l > n - 2) return false;
    if (r < 0 || r > n - 2) return false;
    return true;
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
        cin >> n >> u >> r >> d >> l; flag[0] = 0;
        for (i = 0; i < 16; i++) {
            if (solve(i, u, d, l, r)) flag[0] = 1;
        }

        if (flag[0] == 1) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}