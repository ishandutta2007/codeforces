// 1167F
// Scalar Queries

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 1000000007
#define maxn 500010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn], fn[2][maxn], p;
vector<array<ll, 2>> f;

void upd(ll ty, ll p, ll x) {
    while (p <= n) {
        fn[ty][p] += x;
        p += (p & (-p));
    }
}

ll ps(ll ty, ll p) {
    ll x = 0;
    while (p > 0) {
        x += fn[ty][p];
        p -= (p & (-p));
    }
    return x;
}

ll rs(ll ty, ll l, ll r) {
    return ps(ty, r) - ps(ty, l - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i]; f.pb({a[i], i + 1});
    }

    sort(f.begin(), f.end());

    res = 0;
    for (auto u : f) {
        upd(0, u[1], u[1]);
        res += ((u[0] * (n - u[1] + 1)) % mod) * (rs(0, 1, u[1]) % mod); res %= mod;
        res += ((u[0] * u[1]) % mod) * (rs(1, u[1], n) % mod); res %= mod;
        upd(1, u[1], n - u[1] + 1);
    }

    cout << res;

    return 0;
}