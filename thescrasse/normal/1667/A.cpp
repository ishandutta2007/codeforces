#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 5010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];

ll solve(ll p) {
    ll i, r = 0;
    b[p] = 0;
    for (i = p - 1; i >= 1; i--) {
        b[i] = a[i] * (b[i + 1] / a[i]) + a[i];
        r += (b[i] / a[i]);
    }
    for (i = p + 1; i <= n; i++) {
        b[i] = a[i] * (b[i - 1] / a[i]) + a[i];
        r += (b[i] / a[i]);
    }

    /* cout << "solve" _ p << nl;
    for (i = 1; i <= n; i++) cout << b[i] << ' ';
    cout << nl; */
    return r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }

    res = INF;
    for (i = 1; i <= n; i++) res = min(res, solve(i));

    cout << res << nl;

    return 0;
}