#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 1000000007
#define maxn 500010
#define maxf 2000010
#define maxh 1000005

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll fc[maxn], _f[maxf], r1, r2, p;

ll &f(ll x) {
    return _f[x + maxh];
}

ll calc(ll l, ll r) {
    return (((r - l + 1) * (l + r)) / 2) % mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    fc[0] = 1;
    for (i = 1; i < maxn; i++) fc[i] = (i * fc[i - 1]) % mod;

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i]; f(a[i] - 1)++; f(-a[i] - 1)--;
    }

    r1 = 0; r2 = 1; p = 0;
    for (i = maxh; i >= -maxh; i--) {
        r2 = (r2 * fc[f(i)]) % mod;
        r1 = (r1 - i * calc(p + 1, p + f(i))) % mod;
        r1 = (r1 + mod) % mod;
        p += f(i);
        if (i - 2 + maxh >= 0) f(i - 2) += f(i);

        // if (abs(i) <= 10) cout << i _ f(i) _ r1 _ r2 << nl;
    }

    cout << r1 _ r2 << nl;

    return 0;
}