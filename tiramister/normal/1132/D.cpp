#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

using lint = long long;

constexpr lint MAX = 1LL << 45;

void solve() {
    int n, k;
    std::cin >> n >> k;
    --k;

    std::vector<lint> xs(n), ys(n);
    for (auto& x : xs) std::cin >> x;
    for (auto& y : ys) std::cin >> y;

    lint ok = MAX, ng = -1;
    while (ok - ng > 1) {
        auto mid = (ok + ng) / 2;

        auto nxs = xs;

        MinHeap<std::pair<lint, int>> heap;
        for (int i = 0; i < n; ++i) {
            heap.emplace(nxs[i] / ys[i], i);
        }

        bool judge = true;
        for (int t = 0; t < k; ++t) {
            auto i = heap.top().second;
            heap.pop();

            if (nxs[i] - ys[i] * t < 0) judge = false;
            nxs[i] += mid;
            heap.emplace(nxs[i] / ys[i], i);
        }

        for (int i = 0; i < n; ++i) {
            if (nxs[i] - ys[i] * k < 0) judge = false;
        }

        if (judge) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    std::cout << (ok == MAX ? -1 : ok) << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}