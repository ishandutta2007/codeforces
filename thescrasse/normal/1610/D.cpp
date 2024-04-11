#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 1000000007
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll f[maxn], ps[maxn], pw[maxn];

ll v2(ll x) {
    ll r = 0;
    while (x % 2 == 0) {
        x /= 2; r++;
    }
    return r;
}

ll cn(ll x) {
    if (x == 0) return 0;
    return pw[x - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    pw[0] = 1;
    for (i = 1; i < maxn; i++) pw[i] = (2 * pw[i - 1]) % mod;

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i]; a[i] = v2(a[i]); f[a[i]]++;
    }

    for (i = 40; i >= 0; i--) ps[i] = ps[i + 1] + f[i];

    for (i = 1; i <= 40; i++) {
        res = (res + cn(f[i]) * pw[ps[i + 1]]) % mod;
        // cout << i _ res << nl;
    }

    res = (pw[n] - res - 1 + 2 * mod) % mod;
    cout << res << nl;

    return 0;
}