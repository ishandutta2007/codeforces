#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> a(N), b(N);
        for (int u = 1; u < N; ++u) {
            cin >> a[u];
        }
        for (int u = 1; u < N; ++u) {
            cin >> b[u];
        }
        vector<vector<int>> E(N);
        for (int j = 0; j < M; ++j) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            E[u].push_back(v);
            E[v].push_back(u);
        }
        auto check = [&](long long P) {
            vector<bool> dead(N);
            dead[0] = true;
            while (true) {
                vector<long long> add(N);
                vector<int> p(N, -1);
                queue<int> q;
                for (int u = 0; u < N; ++u) {
                    if (dead[u]) {
                        p[u] = u;
                        q.push(u);
                    }
                }
                while (not q.empty()) {
                    int u = q.front();
                    q.pop();
                    for (auto v : E[u]) {
                        if (p[v] == -1 && P + add[u] > a[v]) {
                            p[v] = u;
                            add[v] = add[u] + b[v];
                            q.push(v);
                        }
                    }
                }
                bool converged = true;
                for (int u = 0; u < N; ++u) {
                    if (p[u] == -1) continue;
                    for (auto v : E[u]) {
                        if (not dead[v] && p[v] != u && p[u] != v && p[v] != -1) {
                            converged = false;
                            for (int w : {u, v}) {
                                while (not dead[w]) {
                                    P += b[w];
                                    dead[w] = true;
                                    w = p[w];
                                }
                            }
                        }
                    }
                }
                if (converged) break;
            }
            return !count(dead.begin(), dead.end(), false);
        };
        int L = 0, R = *max_element(a.begin(), a.end()) + 1;
        while (L + 1 < R) {
            int mid = (L + R) / 2;
            check(mid) ? R = mid : L = mid;
        }
        cout << R << '\n';
    }
    exit(0);
}