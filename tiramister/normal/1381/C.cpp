#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

template <class T>
using MaxHeap = std::priority_queue<T>;

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;

    std::vector<int> xs(n);
    for (auto& x : xs) {
        std::cin >> x;
        --x;
    }

    std::vector<std::vector<int>> idxs(n + 1);
    for (int i = 0; i < n; ++i) idxs[xs[i]].push_back(i);

    int free = 0;
    while (!idxs[free].empty()) ++free;

    std::vector<int> ans(n, -1);

    MaxHeap<std::pair<int, int>> heap;
    for (int i = 0; i <= n; ++i) {
        heap.emplace(idxs[i].size(), i);
    }

    for (int q = 0; q < a; ++q) {
        auto i = heap.top().second;
        heap.pop();

        ans[idxs[i].back()] = i;
        idxs[i].pop_back();
        heap.emplace(idxs[i].size(), i);
    }

    int m = n - a;

    std::vector<int> pos, is;
    for (int i = 0; i <= n; ++i) {
        while (!idxs[i].empty()) {
            int p = idxs[i].back();
            idxs[i].pop_back();

            pos.push_back(p);
            is.push_back(i);
        }
    }

    std::rotate(is.begin(), is.begin() + m / 2, is.end());
    int match = n - b;
    for (int i = 0; i < m; ++i) {
        if (is[i] == xs[pos[i]]) {
            is[i] = free;
            --match;
        }
    }

    if (match < 0) {
        std::cout << "NO\n";
        return;
    }

    for (int i = 0; i < m && match > 0; ++i) {
        if (is[i] != free) {
            is[i] = free;
            --match;
        }
    }

    for (int i = 0; i < m; ++i) {
        ans[pos[i]] = is[i];
    }

    std::cout << "YES\n";
    for (auto i : ans) std::cout << i + 1 << " ";
    std::cout << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}