// 1175F
// The Number of Subpermutations

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 300010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, s, l, r;
bitset<128> bt[maxn], tg[maxn], ps[maxn];
vector<ll> v;

bitset<128> hs(ll l, ll r) {
    return ps[r] ^ ps[l - 1];
}

void solve() {
    v.clear();
    for (i = 1; i <= n; i++) {
        if (a[i] == 1) v.pb(i);
    }
    v.pb(n + 1);

    for (i = 1; i <= n; i++) {
        ps[i] = ps[i - 1] ^ bt[a[i]];
    }

    s = v.size();
    for (i = 0; i < s - 1; i++) {
        l = v[i]; r = v[i + 1]; m = 1;
        for (j = l + 1; j < r; j++) {
            m = max(m, a[j]);
            if (m > j) continue;
            // cout << j - m + 1 << ' ' << j << nl;
            if (hs(j - m + 1, j) == tg[m]) res++;
        }
    }
}

int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i]; res += (a[i] == 1);
    }

    for (i = 1; i <= n; i++) {
        bt[i] |= uniform_int_distribution<ll>(0, ULLONG_MAX)(rng); bt[i] <<= 64;
        bt[i] |= uniform_int_distribution<ll>(0, ULLONG_MAX)(rng);
    }

    for (i = 1; i <= n; i++) {
        tg[i] = tg[i - 1] ^ bt[i];
    }

    solve(); reverse(a + 1, a + n + 1); solve();

    cout << res << nl;

    return 0;
}