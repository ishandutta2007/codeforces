#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

template <class T>
using MaxHeap = std::priority_queue<T>;
template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

void solve() {
    int q, x;
    std::cin >> q >> x;

    std::vector<int> cnt(x, 0);

    MinHeap<std::pair<int, int>> heap;
    for (int i = 0; i < x; ++i) {
        heap.emplace(cnt[i] * x + i, i);
    }

    while (q--) {
        int y;
        std::cin >> y;
        y %= x;
        ++cnt[y];

        while (!heap.empty()) {
            int v, i;
            std::tie(v, i) = heap.top();

            int nv = cnt[i] * x + i;
            if (nv > v) {
                heap.pop();
                heap.emplace(nv, i);
            } else {
                std::cout << v << "\n";
                break;
            }
        }
    }
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}