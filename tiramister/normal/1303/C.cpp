#include <iostream>
#include <numeric>
#include <vector>

constexpr int X = 26;

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.length();

    std::vector<std::vector<int>> graph(X, std::vector<int>(X, 0));
    for (int i = 0; i + 1 < n; ++i) {
        int u = s[i] - 'a',
            v = s[i + 1] - 'a';
        graph[u][v] = graph[v][u] = true;
    }

    std::vector<int> deg(X);
    for (int v = 0; v < X; ++v) {
        deg[v] = std::accumulate(graph[v].begin(), graph[v].end(), 0);
    }

    std::string ans;
    for (int v = 0; v < X; ++v) {
        if (deg[v] == 0) {
            ans.push_back(v + 'a');
            deg[v] = -1;
        } else if (deg[v] == 1) {
            int u = v;
            while (true) {
                if (deg[u] > 1) {
                    std::cout << "NO" << std::endl;
                    return;
                }
                deg[u] = -1;

                ans.push_back(u + 'a');
                bool found = false;

                for (int x = 0; x < X; ++x) {
                    if (!graph[u][x]) continue;
                    graph[u][x] = graph[x][u] = 0;
                    --deg[x];
                    u = x;
                    found = true;
                    break;
                }

                if (!found) break;
            }
        }
    }

    if (ans.length() < X) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl
                  << ans << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}