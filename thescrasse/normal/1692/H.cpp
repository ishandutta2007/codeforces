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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
array<ll, 4> rs;
multiset<array<ll, 2>> st;
map<ll, vector<array<ll, 2>>> adj;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; adj.clear();
        for (i = 1; i <= n; i++) {
            cin >> a; adj[a].pb({i, i});
        }

        rs = {0, 0, 0, 0};
        for (auto [id, v] : adj) {
            st.clear();
            for (i = 0; i < v.size(); i++) {
                v[i][0] -= (2 * i); st.insert(v[i]);
                auto it = --st.end();
                rs = max(rs, {(*it)[0] - v[i][0], id, (*it)[1], v[i][1]});
            }

            /* cout << "adj" _ id << nl;
            for (i = 0; i < v.size(); i++) {
                cout << v[i][0] _ v[i][1] << nl;
            } */
        }

        cout << rs[1] _ rs[2] _ rs[3] << nl;
    }

    return 0;
}