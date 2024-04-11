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
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<pair<int, int>>> c(n);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        c[x].emplace_back(y, z);
    }
    long long inf = (long long) 1e18;
    // vector a(n, vector(n, vector<long long>(n, inf)));
    // for (int k = 0; k < n; k++) {
    //     for (int i = 0; i < n; i++) {
    //         for (auto& [y, z] : c[i]) {
    //             a[k][i][y] = z;
    //             y = (y + 1) % n;
    //         }
    //         for (int j = 0; j < 2 * n; j++) {
    //             a[k][i][(j + 1) % n] = min(a[k][i][(j + 1) % n], a[k][i][j % n] + 1);
    //         }
    //         a[k][i][i] = 0;
    //     }
    // }
    vector d(n, vector<long long>(n, inf));
    for (int k = 0; k < n; k++) {
        priority_queue<tuple<long long, int>, vector<tuple<long long, int>>, greater<tuple<long long, int>>> pq;
        pq.emplace(0, k);
        d[k][k] = 0;
        while (!pq.empty()) {
            auto [exp, v] = pq.top();
            pq.pop();
            if (d[k][v] != exp) {
                continue;
            }
            int p = (int) (d[k][v] % n);
            vector<long long> a(n, inf);
            for (auto [y, z] : c[v]) {
                a[(y + p) % n] = z;
            }
            for (int i = 0; i < 2 * n; i++) {
                a[(i + 1) % n] = min(a[(i + 1) % n], a[i % n] + 1);
            }
            a[v] = 0;
            for (int to = 0; to < n; to++) {
                if (d[k][to] > d[k][v] + a[to]) {
                    d[k][to] = d[k][v] + a[to];
                    pq.emplace(d[k][to], to);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << d[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}