#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> ps(n);
    for (auto& p : ps) std::cin >> p.first >> p.second;

    std::vector<int> idx(n);
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(),
              [&](int i, int j) {
                  return ps[i].first == ps[j].first ? ps[i].second > ps[j].second
                                                    : ps[i].first < ps[j].first;
              });

    for (int i = 0; i + 1 < n; ++i) {
        int x = idx[i], y = idx[i + 1];
        if (ps[x].first <= ps[y].first && ps[y].second <= ps[x].second) {
            std::cout << y + 1 << " " << x + 1 << std::endl;
            return;
        }
    }

    std::cout << -1 << " " << -1 << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}