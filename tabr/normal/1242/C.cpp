#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k, m = 0;
    cin >> k;
    vector<int> n(k);
    vector<vector<ll>> a(k);
    vector<ll> s(k);
    ll sum = 0;
    map<ll, int> mp;
    for (int i = 0, id = 1; i < k; i++) {
        cin >> n[i];
        m += n[i];
        a[i].resize(n[i]);
        for (int j = 0; j < n[i]; j++) {
            cin >> a[i][j];
            sum += a[i][j];
            s[i] += a[i][j];
            mp[a[i][j]] = id;
            id++;
        }
    }
    if (sum % k != 0) {
        cout << "No" << '\n';
        return 0;
    }
    ll val = sum / k;
    vector<int> to(m + 1);
    vector<int> col(m + 1);
    vector<ll> b(m + 1);
    col[0] = -1;
    for (int i = 0, id = 1; i < k; i++) {
        for (int j = 0; j < n[i]; j++) {
            b[id] = a[i][j];
            ll t = val - s[i] + a[i][j];
            to[id] = mp[t];
            col[id] = i;
            id++;
        }
    }
    debug(to);
    // vector<vector<pair<int, int>>> x(k);  // bit, id
    vector<vector<int>> x(1 << k);
    int rc, bt;
    function<void(int, int)> dfs = [&](int v, int p) {
        if (to[v] == p) {
            x[bt] = {p};
            return;
        }
        if (col[to[v]] <= rc) return;
        if (bt & (1 << col[to[v]])) return;
        bt |= 1 << col[to[v]];
        dfs(to[v], p);
    };
    for (int i = 0, id = 1; i < k; i++) {
        rc = i;
        for (int j = 0; j < n[i]; j++) {
            bt = 1 << i;
            dfs(id, id);
            id++;
        }
    }
    for (int i = 0; i < (1 << k); i++) {
        if (!x[i].empty()) continue;
        for (int j = i; j > 0 && j > j ^ i; j = (j - 1) & i) {
            if (!x[j].empty() && !x[j ^ i].empty()) {
                x[i] = x[j];
                x[i].insert(x[i].end(), x[j ^ i].begin(), x[j ^ i].end());
                break;
            }
        }
    }
    if (x[(1 << k) - 1].empty()) {
        cout << "No" << '\n';
        return 0;
    }
    cout << "Yes" << '\n';
    debug(x[(1 << k) - 1]);
    vector<ll> ans(k), bns(k);
    vector<int> t = x[(1 << k) - 1];
    for (int i = 0; i < t.size(); i++) {
        int q = t[i];
        while (true) {
            bns[col[to[q]]] = col[q];
            ans[col[q]] = b[q];
            q = to[q];
            if (q == t[i]) break;
        }
    }
    for (int i = 0; i < k; i++) {
        cout << ans[i] << " " << bns[i] + 1 << '\n';
    }
    return 0;
}