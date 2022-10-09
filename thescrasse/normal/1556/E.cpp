#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];
ll st[20][maxn][2], l, r, q, p2[maxn];

ll rmq_min(ll l, ll r) {
    if (l > r) return -INF;
    ll p = p2[r - l + 1];
    ll k = (1 << p);
    return min(st[p][l][0], st[p][r - k + 1][0]);
}

ll rmq_max(ll l, ll r) {
    if (l > r) return -INF;
    ll p = p2[r - l + 1];
    ll k = (1 << p);
    return max(st[p][l][1], st[p][r - k + 1][1]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    for (i = 2; i < maxn; i++) {
        p2[i] = p2[i / 2] + 1;
    }

    cin >> n >> q; n++;
    for (i = 2; i <= n; i++) {
        cin >> a[i];
    }
    for (i = 2; i <= n; i++) {
        cin >> b[i]; a[i] = (a[i] + a[i - 1] - b[i]);
    }

    for (j = 1; j <= n; j++) {
        st[0][j][0] = a[j]; st[0][j][1] = a[j];
    }
    for (i = 1; i <= 19; i++) {
        for (j = 1; j <= n; j++) {
            k = (1 << (i - 1));
            if (j + k >= n + 1) continue;
            st[i][j][0] = min(st[i - 1][j][0], st[i - 1][j + k][0]);
            st[i][j][1] = max(st[i - 1][j][1], st[i - 1][j + k][1]);
        }
    }

    /* for (i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << nl; */

    while (q--) {
        cin >> l >> r; l++; r++;
        if (a[l - 1] != a[r]) cout << -1 << nl;
        else cout << rmq_max(l - 1, r) - rmq_min(l - 1, r) << nl;
    }

    return 0;
}