#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn], q[maxn], l, r;
vector<ll> v, w, adj[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n % 2 == 0) {
        for (i = 0; i < n; i++) {
            if (i % 2 == 0) q[i] = (n + i) / 2 + 1;
            else q[i] = i / 2 + 1;
        }
    } else {
        for (i = 0; i < n; i++) {
            if (i % 2 == 0) q[i] = i / 2 + 1;
            else q[i] = (n + i) / 2 + 1;
        }
    }

    res = 0;
    for (i = 0; i < n; i++) {
        l = (i + 1) / 2; r = n - i / 2;
        for (j = 0; j < n; j++) {
            if (a[j] == q[i]) k = j;
        }

        v.clear();
        for (j = r; j < n; j++) v.pb(a[j]);
        for (j = k; j < r; j++) v.pb(a[j]);
        for (j = l; j < k; j++) v.pb(a[j]);
        for (j = 0; j < l; j++) v.pb(a[j]);

        for (j = 0; j < n; j++) a[j] = v[j];

        w.clear();
        if (l - 0 > 0) w.pb(l - 0);
        if (k - l > 0) w.pb(k - l);
        if (r - k > 0) w.pb(r - k);
        if (n - r > 0) w.pb(n - r);

        if ((ll)w.size() > 1) {
            res++;
            for (auto u : w) adj[i].pb(u);
        }

        /* for (j = 0; j < n; j++) cout << a[j] << ' ';
        cout << nl; */
    }

    cout << res << nl;
    for (i = 0; i < n; i++) {
        if (adj[i].empty()) continue;
        cout << adj[i].size() << ' ';
        for (auto u : adj[i]) cout << u << ' ';
        cout << nl;
    }

    return 0;
}