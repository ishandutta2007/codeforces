#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int>>> pss(n);
    for (int i = 0; i < m; ++i) {
        int l, r;
        std::cin >> l >> r;
        pss[--l].emplace_back(--r, i);
    }

    int cost = 0;
    std::vector<int> cost1(m, 0);
    auto cost2 = vec(m, vec(m, 0));

    MinHeap<std::pair<int, int>> heap;
    for (int l = 0; l < n; ++l) {
        for (auto p : pss[l]) heap.push(p);

        if (heap.empty()) {
            ++cost;

        } else if (heap.size() == 1) {
            ++cost1[heap.top().second];

        } else if (heap.size() == 2) {
            auto p = heap.top();
            heap.pop();

            ++cost2[p.second][heap.top().second];
            heap.push(p);
        }

        while (!heap.empty() && heap.top().first <= l) heap.pop();
    }

    int cmin = n;
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < j; ++i) {
            cmin = std::min(cmin,
                            cost +
                                cost1[i] + cost1[j] +
                                cost2[i][j] + cost2[j][i]);
        }
    }

    std::cout << n - cmin << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}