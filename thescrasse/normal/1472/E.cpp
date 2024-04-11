#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];
ll rs[maxn], bsl, bsm, bsu;
vector<pair<ll, array<ll, 2>>> v;

void bs(ll x, ll y) {
    // cout << "bs " << i _ x _ y << nl;

    bsl = -1; bsu = n - 1;
    while (bsl != bsu) {
        bsm = (bsl + bsu + 1) / 2;
        if (v[bsm].first >= x) bsu = bsm - 1;
        else bsl = bsm;
    }

    // cout << bsl _ v[bsl].second[0] << nl;

    if (bsl == -1) return;
    if (v[bsl].second[0] < y) rs[i] = v[bsl].second[1];
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
        for (i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
        }

        v.clear();
        for (i = 1; i <= n; i++) {
            v.pb({a[i], {b[i], i}});
        }

        sort(v.begin(), v.end());

        for (i = 1; i < n; i++) {
            v[i].second = min(v[i].second, v[i - 1].second);
        }

        /* for (auto u : v) {
            cout << u.first _ u.second[0] _ u.second[1] << nl;
        } */

        for (i = 1; i <= n; i++) rs[i] = -1;

        for (i = 1; i <= n; i++) {
            bs(a[i], b[i]); bs(b[i], a[i]);
        }

        for (i = 1; i <= n; i++) cout << rs[i] << ' ';
        cout << nl;

        // cout << "----" << nl;
    }

    return 0;
}