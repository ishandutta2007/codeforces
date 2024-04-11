#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

using lint = long long;

constexpr int K = 60;

void solve() {
    int n;
    std::cin >> n;

    std::map<int, std::vector<std::pair<int, int>>> idxs;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;

        int cnt = 0;
        while (x % 2 == 0) {
            x /= 2;
            ++cnt;
        }

        idxs[x].emplace_back(i, cnt);
    }

    std::vector<lint> ans(n);

    for (const auto& [b, ps] : idxs) {
        std::vector<MinHeap<int>> heaps(K);
        for (auto [i, d] : ps) heaps[d].push(i);

        for (int d = 0; d + 1 < K; ++d) {
            auto& heap = heaps[d];

            while ((int)heap.size() >= 2) {
                int i = heap.top();
                heap.pop();
                int j = heap.top();
                heap.pop();

                ans[i] = 0;
                heaps[d + 1].push(j);
            }

            if (!heap.empty()) {
                lint x = b;
                for (int i = 0; i < d; ++i) x *= 2;

                int i = heap.top();
                ans[i] = x;
            }
        }
    }

    std::vector<lint> rans;
    for (auto a : ans) {
        if (a != 0) rans.push_back(a);
    }

    std::cout << rans.size() << "\n";
    for (auto a : rans) std::cout << a << " ";
    std::cout << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}