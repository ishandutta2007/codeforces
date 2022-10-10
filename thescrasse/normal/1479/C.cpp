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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, l, r, x;
vector<array<ll, 3>> rs;

void ins(ll a, ll b, ll c) {
    rs.pb({a, b, c});
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> l >> r; k = r - l;
    n = 22;
    for (i = 2; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (j == n) x = 1;
            else x = (1 << (n - 1 - j));
            ins(i, j, x);
        }
    }

    ins(1, n, l);
    m = l;
    for (i = 1; i <= n - 1; i++) {
        x = n - 1 - i;
        if ((k >> x) & 1) {
            ins(1, i, m);
            m += (1 << x);
        }
    }

    cout << "YES" << nl;
    cout << n << ' ' << rs.size() << nl;
    for (auto u : rs) cout << u[0] _ u[1] _ u[2] << nl;

    return 0;
}