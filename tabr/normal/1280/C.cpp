#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
//#include "library/debug.cpp"

ll k;
vector<vector<ll>> g;
map<pair<ll, ll>, ll> mp, mp2;

ll dfs(ll v, ll p) {
    ll sbs = 1;
    for (auto u : g[v])
        if (u != p) {
            sbs += dfs(u, v);
        }
    if (p != -1) {
        mp[make_pair(min(p, v), max(p, v))] = min(sbs, 2 * k - sbs);
    }
    return sbs;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> k;
        g.clear();
        mp.clear();
        mp2.clear();
        g.resize(2 * k);
        rep(i, 0, 2 * k - 1) {
            ll a, b, d;
            cin >> a >> b >> d;
            a--, b--;
            g[a].emplace_back(b);
            g[b].emplace_back(a);
            mp2[make_pair(min(a, b), max(a, b))] = d;
        }
        dfs(0, -1);
        ll mn = 0, mx = 0;
        for (auto c : mp) {
            mx += c.second * mp2[c.first];
            mn += c.second % 2 * mp2[c.first];
        }
        cout << mn << ' ' << mx << endl;
    }

    return 0;
}