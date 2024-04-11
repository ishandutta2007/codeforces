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

ll i, i1, j, k, k1, t, n, res, flag[10], a, b, l[maxn], r[maxn], ps[maxn], ss[maxn];
vector<ll> cm;
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
        cin >> n; res = 0; m.clear(); cm.clear();
        for (i = 1; i <= n; i++) {
            cin >> l[i] >> r[i]; cm.pb(l[i]); cm.pb(r[i]);
        }

        for (i = 0; i <= 2 * n + 5; i++) {
            ps[i] = 0; ss[i] = 0;
        }

        sort(cm.begin(), cm.end());
        for (i = 0; i < 2 * n; i++) {
            m[cm[i]] = i + 1;
        }

        for (i = 1; i <= n; i++) {
            l[i] = m[l[i]]; r[i] = m[r[i]];
        }

        for (i = 1; i <= n; i++) {
            ps[r[i]]++; ss[l[i]]++;
        }

        for (i = 1; i <= 2 * n + 5; i++) ps[i] += ps[i - 1];
        for (i = 2 * n + 4; i >= 0; i--) ss[i] += ss[i + 1];

        res = INF;
        for (i = 1; i <= n; i++) {
            res = min(res, ps[l[i] - 1] + ss[r[i] + 1]);
        }

        /* for (i = 1; i <= n; i++) {
            cout << i _ l[i] _ r[i] << nl;
        }

        for (i = 1; i <= 2 * n; i++) {
            cout << i _ ps[i] _ ss[i] << nl;
        } */

        cout << res << nl;
    }

    return 0;
}