#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, W, H;
    std::cin >> N >> W >> H;
    std::map<int, std::vector<std::pair<int, int>>> mp[2];
    std::vector<int> keys;
    for (int i = 0; i < N; ++i) {
        int g, p, t;
        std::cin >> g >> p >> t;
        --g;
        mp[g][p - t].emplace_back(p, i);
        keys.push_back(p - t);
    }
    std::sort(keys.begin(), keys.end());
    keys.erase(std::unique(keys.begin(), keys.end()), keys.end());
    std::vector<std::pair<int, int>> ans(N);
    for (auto k : keys) {
        auto &h = mp[1][k], &v = mp[0][k];
        std::sort(h.begin(), h.end());
        std::sort(v.begin(), v.end());
        int r = std::min(h.size(), v.size());
        for (int j = 0; j < r; ++j) {
            int i = v[v.size() - 1 - j].second;
            ans[i] = {W, h[j].first};

            int k = h[h.size() - 1 - j].second;
            ans[k] = {v[j].first, H};
        }
        for (int j = 0; j + r < v.size(); ++j) {
            int i = v[j].second;
            ans[i] = {v[j + r].first, H};
        }
        for (int j = 0; j + r < h.size(); ++j) {
            int i = h[j].second;
            ans[i] = {W, h[j + r].first};
        }
    }
    for (int i = 0; i < N; ++i) {
        std::cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
    exit(0);
}