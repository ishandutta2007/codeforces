#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <tuple>
#include <queue>
#include <cassert>

template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    std::vector<int> srcs(n - 1);
    std::vector<int> deg(n, 0);
    for (auto& src : srcs) {
        std::cin >> src;
        --src;
        ++deg[src];
    }

    std::vector<int> cmax(n);
    std::iota(cmax.begin(), cmax.end(), 0);

    MinHeap<std::pair<int, int>> heap;
    for (int v = 0; v < n; ++v) {
        if (deg[v] == 0) {
            heap.emplace(cmax[v], v);
        }
    }

    std::vector<int> dsts(n - 1);
    for (int i = n - 2; i >= 0; --i) {
        assert(!heap.empty());

        int src = srcs[i];
        int& dst = dsts[i];

        int max;
        std::tie(max, dst) = heap.top();
        heap.pop();

        cmax[src] = std::max(cmax[src], max);
        if (--deg[src] == 0) {
            heap.emplace(cmax[src], src);
        }
    }

    assert(!heap.empty());
    int root;
    std::tie(std::ignore, root) = heap.top();

    std::cout << root + 1 << "\n";
    for (int i = 0; i < n - 1; ++i) {
        std::cout << srcs[i] + 1 << " " << dsts[i] + 1 << "\n";
    }
    return 0;
}