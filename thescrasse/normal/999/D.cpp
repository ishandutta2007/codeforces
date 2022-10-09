// 999D
// distribuire equamente i resti mod m aggiungendo 1

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a[200010], f[200010], g[200010], mv[200010], r, m1, m2, b, tr, pos, d;
vector<pair<long long, long long>> adj[200010];
vector<pair<long long, long long>> fr;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n >> m;
    r = n / m;
    for (i = 0; i < n; i++) {
        f[i] = -r;
    }
    for (i = 0; i < n; i++) {
        cin >> a[i];
        f[(a[i] % m)]++;
        adj[(a[i] % m)].push_back({a[i], i});
    }

    for (i = 1; i < n; i++) {
        f[i] += f[i - 1];
    }

    m1 = 0;
    m2 = -1;
    for (i = 0; i < m; i++) {
        if (f[i] < m1) {
            m1 = f[i];
            m2 = i;
        }
    }

    for (i = n - 1; i > 0; i--) {
        f[i] -= f[i - 1];
    }

    if (m2 != -1) {
        k = m - m2 - 1;
        for (i = 0; i < m; i++) {
            g[(i + k) % m] = f[i];
        }
    } else {
        k = 0;
        for (i = 0; i < m; i++) {
            g[i] = f[i];
        }
    }

    res = 0;
    for (i = 0; i < m; i++) {
        tr = (i - k + m) % m;
        if (g[i] > 0) {
            while (g[i] > 0) {
                b = adj[tr].back().first;
                pos = adj[tr].back().second;
                adj[tr].pop_back();
                fr.push_back({b, pos});
                g[i]--;
            }
        } else if (g[i] < 0) {
            while (g[i] < 0) {
                b = fr.back().first;
                pos = fr.back().second;
                fr.pop_back();
                d = 0;
                if ((b % m) > tr) {
                    d += m;
                }
                d += (tr - (b % m));
                adj[tr].push_back({b + d, pos});
                g[i]++;
                res += d;
            }
        }
    }

    for (i = 0; i < m; i++) {
        for (auto u : adj[i]) {
            a[u.second] = u.first;
        }
    }

    cout << res << endl;
    for (i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }

    return 0;
}