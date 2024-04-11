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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn], cp[maxn];

ll solve(vector<ll> &a, vector<ll> &b) {
    // cout << "solve" << nl;

    ll la, lb, rb, res, n, m;
    la = 1; lb = 1; rb = 1; res = 0;
    n = a.size(); m = b.size(); n--; m--;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    set<ll> st;
    for (auto u : b) st.insert(u);
    cp[n + 1] = 0;
    for (i = n; i >= 1; i--) {
        if (i == n) cp[i] = 0;
        else cp[i] = cp[i + 1];
        cp[i] += st.count(a[i]);
    }

    /* cout << "cp" << nl;
    for (i = 1; i <= n; i++) cout << cp[i] << ' ';
    cout << nl; */

    while (rb <= m) {
        // cout << "la, lb, rb = " << la _ lb _ rb << nl;

        while (la <= n && a[la] <= b[rb]) la++;

        if (lb > rb) {
            rb++;
        } else if (b[rb] - b[lb] + 2 <= la) {
            res = max(res, rb - lb + 1 + cp[la]);
            rb++;
        } else {
            lb++;
        }
    }

    // cout << "res = " << res << nl;
    return res;
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
        cin >> n >> m;
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (i = 1; i <= m; i++) {
            cin >> b[i];
        }

        vector<ll> ap, an, bp, bn;

        ap.pb(-1); an.pb(-1);
        for (i = 1; i <= n; i++) {
            if (a[i] > 0) ap.pb(a[i]);
            else an.pb(-a[i]);
        }

        bp.pb(-1); bn.pb(-1);
        for (i = 1; i <= m; i++) {
            if (b[i] > 0) bp.pb(b[i]);
            else bn.pb(-b[i]);
        }

        res = solve(ap, bp) + solve(an, bn);

        cout << res << nl;
    }

    return 0;
}