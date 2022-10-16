#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int N = 400;
const int MOD = 998244353;

int n, m, d[N][N], h[N], x[N];
vector<int> g[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    for (int i = 0; i < n; ++i) {
        queue<int> q({i});
        fill(d[i], d[i]+n, n+1);
        d[i][i] = 0;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int j : g[v]) {
                if (d[i][j] > d[i][v] + 1) {
                    d[i][j] = d[i][v] + 1;
                    q.push(j);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)  {
            int ans = 1;

            for (int v = 0; v < n; ++v) {
                h[v] = d[v][j] + d[v][i] - d[j][i];
                if (h[v] < 0 || h[v] % 2) ans = 0;
                h[v] /= 2;

                x[v] = d[j][v] - d[i][v] + d[i][j];
                if (x[v] < 0 || x[v] % 2 || x[v] > 2*d[i][j]) ans = 0;
                x[v] /= 2;
            }

            if (ans != 0) {
                vector<int> cnt(d[i][j]+1);
                for (int v = 0; v < n; ++v) {
                    if (h[v] == 0) cnt[x[v]]++;
                }
                for (int t = 0; t <= d[i][j]; ++t) {
                    if (cnt[t] != 1) ans = 0;
                }

                if (ans != 0) {
                    for (int v = 0; v < n; ++v) {
                        if (h[v] == 0) continue;
                        int cnt = 0;
                        for (int u : g[v]) {
                            if (h[u] + 1 == h[v]) cnt++;
                        }
                        ans = (long long) ans * cnt % MOD;
                    }
                }
            }

            cout << ans << ' ';
        }
        cout << '\n';
    }
}