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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn], sz;
vector<ll> adj[maxn], cl;
set<ll> st;

bool cmp(ll a, ll b) {
    return (a > b);
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
        cin >> n; st.clear();
        for (i = 1; i <= n; i++) {
            adj[i].clear(); adj[i].pb(INF); st.insert(i);
        }
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (i = 1; i <= n; i++) {
            cin >> b[i]; adj[a[i]].pb(b[i]);
        }

        for (i = 1; i <= n; i++) {
            sort(adj[i].begin(), adj[i].end(), cmp);
            adj[i][0] = 0;
            sz = (ll)adj[i].size() - 1;
            for (j = 1; j <= sz; j++) adj[i][j] += adj[i][j - 1];
        }

        for (i = 1; i <= n; i++) {
            cl.clear(); res = 0;
            for (auto u : st) {
                sz = (ll)adj[u].size() - 1;
                if (sz < i) {
                    cl.pb(u); continue;
                }
                for (j = i; j <= sz; j += i) res += adj[u][j] - adj[u][j - i];
            }
            cout << res << ' ';

            for (auto u : cl) st.erase(u);
        }

        cout << nl;
    }

    return 0;
}