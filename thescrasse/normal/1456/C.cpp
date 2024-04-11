#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 500010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, s, tt, l, sl, p0, t0, sm;
array<ll, 2> p[maxn];
vector<ll> adj[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> k; k++;
    for (i = 0; i < n; i++) {
        cin >> a[i]; sm += a[i];
    }

    sort(a, a + n);

    for (i = 0; i < n; i++) {
        adj[i % k].pb(a[i]);
        s = adj[i % k].size();
        tt += s * a[i]; p[i] = {i % k, s};
    }

    res = tt;
    l = (ll)adj[0].size() + 1;
    for (i = n - 1; i >= 0; i--) {
        if (p[i][0] == 0) {
            p0 += a[i]; l--; res = max(res, tt);
            // cout << i _ a[i] _ p0 _ tt _ l << nl;
            continue;
        }
        tt -= p[i][1] * a[i];
        tt += p0; tt += l * a[i]; p0 += a[i];
        res = max(res, tt);
        // cout << i _ a[i] _ p0 _ tt _ l << nl;
    }

    cout << res - sm;

    return 0;
}