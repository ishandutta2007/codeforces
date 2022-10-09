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
ll bsl, bsm, bsu, tt;
map<array<ll, 2>, ll> mp;

ll ask(ll l, ll r) {
    if (l < 1 || l > r || r > n) return -1;
    if (mp[{l, r}] != 0) return mp[{l, r}] - 1;
    cout << "?" _ l _ r << nf;
    ll x; cin >> x;
    mp[{l, r}] = x + 1;
    return x;
}

void clm(ll a, ll b, ll c) {
    cout << "!" _ a _ b _ c << nf;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif */

    cin >> t;
    while (t--) {
        cin >> n; mp.clear();

        tt = ask(1, n);
        bsl = 1; bsu = n + 1;
        while (bsl != bsu) {
            bsm = (bsl + bsu) / 2;
            if (ask(1, bsm) != 0) bsu = bsm;
            else bsl = bsm + 1;
        }
        a = bsl - 1;

        k = tt - ask(a + 1, n);
        b = a + k + 1;
        tt -= ((k * (k + 1)) / 2);

        bsl = 1; bsu = 1000000010;
        while (bsl != bsu) {
            bsm = (bsl + bsu) / 2;
            if ((bsm * (bsm - 1)) / 2 >= tt) bsu = bsm;
            else bsl = bsm + 1;
        }

        clm(a, b, b + bsl - 1);
    }

    return 0;
}