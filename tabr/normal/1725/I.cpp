#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 998244353;

int main() {
    ll N;
    cin >> N;
    vector<pair<int, int>> edge;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        edge.push_back({u - 1, v - 1});
    }

    vector<int> root(N);
    vector<vector<int>> ver(N);
    for (int i = 0; i < N; i++) {
        root[i] = i;
        ver[i].push_back(i);
    }

    ll res = 1;
    for (auto [u, v] : edge) {
        int pu = root[u], pv = root[v];
        ll su = ver[pu].size(), sv = ver[pv].size();
        if (su > sv) {
            swap(pu, pv);
        }

        res *= (su * sv % MOD);
        res %= MOD;
        res *= (su * sv % MOD);
        res %= MOD;

        for (auto a : ver[pu]) {
            root[a] = pv;
            ver[pv].push_back(a);
        }
        ver[pu].clear();
        vector<int>().swap(ver[pu]);
    }

    for (ll i = 0; i < N - 1; i++) {
        res = res * (2 * i + 1) % MOD;
    }

    cout << res << endl;
}