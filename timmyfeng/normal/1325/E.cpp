#include <bits/stdc++.h>
using namespace std;

const int MX = 1e6;

vector<int> adj[MX + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0, a; i < n; ++i) {
        cin >> a;
        vector<int> pf;
        for (int j = 2; j * j <= a; ++j) {
            int pow = 0;
            while (a % j == 0) {
                a /= j;
                ++pow;
            }
            if (pow % 2) {
                pf.push_back(j);
            }
        }
        if (a > 1) {
            pf.push_back(a);
        }

        while (pf.size() < 2) {
            pf.push_back(1);
        }
        adj[pf[0]].push_back(pf[1]);
        adj[pf[1]].push_back(pf[0]);
    }

    int ans = 1e9;
    vector<int> dist(MX + 1, -1);
    for (int i = 1; i <= 1000; ++i) {
        fill(dist.begin(), dist.end(), -1);
        queue<pair<int, int>> qu;
        qu.push({i, 0});
        dist[i] = 0;
        while (!qu.empty()) {
            int u, p;
            tie(u, p) = qu.front();
            qu.pop();
            for (auto c : adj[u]) {
                if (c != p) {
                    if (dist[c] != -1) {
                        ans = min(ans, dist[u] + dist[c] + 1);
                    } else {
                        dist[c] = dist[u] + 1;
                        qu.push({c, u});
                    }
                }
            }
        }
    }
    cout << (ans == 1e9 ? -1 : ans);
}