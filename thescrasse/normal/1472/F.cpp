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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, c;
vector<array<ll, 3>> v, w;
map<ll, ll> f;

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
        v.clear(); w.clear(); f.clear();
        v.pb({-1, -1, 1}); flag[0] = 1;
        for (i = 1; i <= m; i++) {
            cin >> a >> b; v.pb({b, a, 1}); f[b]++;
        }

        sort(v.begin(), v.end());

        for (i = 1; i <= m; i++) {
            v[i][2] = f[v[i][0]];
            if (v[i][1] == 2 && v[i][2] == 2) v[i][2] = -1;
            // cout << v[i][0] _ v[i][1] _ v[i][2] << nl;
        }

        for (i = 1; i <= m; i++) {
            a = v[i][0]; b = v[i][1]; c = v[i][2];
            if (c == -1) continue;
            // cout << a _ b _ c << nl;
            if (c == 2) {
                if (w.size() == 1) {
                    flag[0] = 0; break;
                }
            } else {
                w.pb({a, b, c});
                if (w.size() == 1) continue;
                if (((w[0][0] + w[1][0]) % 2) ^ (w[0][1] == w[1][1])) {
                    flag[0] = 0; break;
                }
                w.clear();
            }
        }

        if (flag[0] == 1 && w.empty()) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}