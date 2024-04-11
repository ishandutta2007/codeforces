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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, mn, l;
vector<ll> adj[maxn];
bool vis[maxn];
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> s; n = s.size(); s = '#' + s;

        for (i = 1; i <= 26; i++) adj[i].clear();
        for (i = 1; i <= n; i++) {
            adj[(ll)s[i] - 'a' + 1].pb(i);
        }

        m = 0;
        for (i = 1; i <= 26; i++) {
            if (!adj[i].empty()) {
                vis[i] = false; m++;
            } else {
                vis[i] = true;
            }
        }

        l = 0;
        for (i = 1; i <= m; i++) {
            for (j = 26; j >= 1; j--) {
                if (vis[j]) continue;

                flag[0] = 1;
                mn = *(upper_bound(adj[j].begin(), adj[j].end(), l));

                for (k = 1; k <= 26; k++) {
                    if (k == j) continue;
                    if (vis[k]) continue;
                    if (adj[k].back() < mn) flag[0] = 0;
                }

                if (flag[0] == 1) {
                    cout << (char)(j + 'a' - 1);
                    vis[j] = true; l = mn; break;
                }
            }
        }

        cout << nl;
    }

    return 0;
}