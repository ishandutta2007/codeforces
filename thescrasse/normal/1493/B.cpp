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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, h, hs, ms, md, x, y;
string s;
array<ll, 3> rs;
ll nc[10] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

ll mrr(ll x) {
    ll a, b;
    a = x / 10; b = x % 10;
    if (nc[a] == -1 || nc[b] == -1) return -1;
    return nc[a] + 10 * nc[b];
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
        cin >> h >> m >> s; md = h * m;
        hs = 10 * (ll)(s[0] - '0') + (ll)(s[1] - '0');
        ms = 10 * (ll)(s[3] - '0') + (ll)(s[4] - '0');
        // cout << hs _ ms << nl;

        rs = {INF, INF, INF};
        for (i = 0; i < h; i++) {
            for (j = 0; j < m; j++) {
                x = mrr(j); y = mrr(i);
                if (x == -1 || y == -1 || x >= h || y >= m) continue;
                // cout << h _ m _ i _ j _ x _ y << nl;
                rs = min(rs, {((m * i + j) - (m * hs + ms) + md) % md, i, j});
            }
        }

        cout << setfill('0') << setw(2);
        cout << rs[1] << ":";
        cout << setfill('0') << setw(2);
        cout << rs[2] << nl;
    }

    return 0;
}