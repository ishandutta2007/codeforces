#include <iostream>
#include <algorithm>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

constexpr int INF = 1 << 30;

int n, k;
std::vector<std::vector<std::vector<std::pair<int, int>>>> zigs;
std::vector<int> vs;
std::vector<bool> used;

int dfs(int d) {
    if (d == 0) {
        int sum = 0;
        for (int i = 0; i < k; i += 2) {
            int u = vs[i], v = vs[i + 2];

            bool spanned = false;
            for (const auto& p : zigs[u][v]) {
                if (used[p.second]) continue;

                sum += p.first;
                spanned = true;
                break;
            }

            if (!spanned) return INF;
        }
        return sum;
    }

    int ret = INF;
    for (int v = 0; v < n; ++v) {
        bool prev = used[v];
        used[v] = true;
        vs[d] = v;

        ret = std::min(ret, dfs(d - 2));

        used[v] = prev;
        vs[d] = -1;
    }
    return ret;
}

void solve() {
    std::cin >> n >> k;

    auto cost = vec(n, vec(n, 0));
    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            std::cin >> cost[u][v];
        }
    }

    zigs.resize(n);
    for (int u = 0; u < n; ++u) {
        zigs[u].resize(n);
        for (int v = 0; v < n; ++v) {
            auto& zig = zigs[u][v];

            for (int w = 0; w < n; ++w) {
                if (u == w || v == w) continue;
                zig.emplace_back(cost[u][w] + cost[w][v], w);
            }
            std::sort(zig.begin(), zig.end());
        }
    }

    vs.assign(k + 1, -1);
    vs[0] = vs[k] = 0;

    used.assign(n, false);
    used[0] = true;

    std::cout << dfs(k - 2) << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}