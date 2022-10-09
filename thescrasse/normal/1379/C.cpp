#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, x, y, pa, pb, nw, z;
vector<array<ll, 3>> sa, sb;
bool visited[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        sa.clear(); sb.clear();
        cin >> n >> m;
        for (i = 0; i < m; i++) {
            visited[i] = false;
            cin >> a >> b;
            sa.pb({a, b, i}); sb.pb({-b, a, i});
        }

        sort(sa.begin(), sa.end());
        sort(sb.begin(), sb.end());
        for (auto &u : sb) u[0] *= -1;

        pa = m - 1; pb = 0; res = 0; k = 0; z = 0;
        while (true) {
            if (z <= n - 2 && pa >= 0 && sa[pa][0] >= sb[pb][0]) {
                k += sa[pa][0]; z++; visited[sa[pa][2]] = true; pa--;
            } else {
                if (visited[sb[pb][2]]) {
                    nw = k + (n - z) * sb[pb][0];
                } else {
                    nw = sb[pb][1] + k + (n - z - 1) * sb[pb][0];
                }
                res = max(res, nw);
                // cout << pb << ' ' << nw << ' ' << k << ' ' << z << nl;
                pb++;
                if (pb == m) break;
            }
        }

        k = 0;
        if (n <= m) {
            for (i = 0; i < n; i++) {
                k += sa[m - i - 1][0];
            }
            res = max(k, res);
        }

        cout << res << nl;
    }

    return 0;
}