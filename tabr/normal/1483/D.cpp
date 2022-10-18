#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> from(m), to(m);
    vector<long long> w(m);
    long long inf = (long long)1e18;
    vector<vector<long long>> d(n, vector<long long>(n, inf));
    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i] >> w[i];
        from[i]--, to[i]--;
        d[from[i]][to[i]] = d[to[i]][from[i]] = w[i];
    }
    for (int i = 0; i < n; i++) {
        d[i][i] = 0;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int q;
    cin >> q;
    vector<int> u(q), v(q);
    vector<long long> l(q);
    vector<vector<long long>> z(n, vector<long long>(n, -1));
    for (int i = 0; i < q; i++) {
        cin >> u[i] >> v[i] >> l[i];
        u[i]--, v[i]--;
        z[u[i]][v[i]] = z[v[i]][u[i]] = l[i];
    }
    vector<int> ans(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                z[i][k] = max(z[i][k], z[i][j] - d[k][j]);
            }
        }
        for (int j = 0; j < m; j++) {
            if (w[j] <= max(z[i][to[j]] - d[i][from[j]], z[i][from[j]] - d[i][to[j]])) {
                ans[j] = 1;
            }
        }
    }
    cout << accumulate(ans.begin(), ans.end(), 0) << '\n';
    return 0;
}