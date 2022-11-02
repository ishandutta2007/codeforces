#include <iostream>
#include <queue>

template <class T>
using MaxHeap = std::priority_queue<T>;

void solve() {
    int n, k;
    std::cin >> n >> k;

    int prev;
    std::cin >> prev;

    MaxHeap<int> heap;
    for (int i = 0; i < n - 1; ++i) {
        int x;
        std::cin >> x;
        heap.push(x - prev);
        prev = x;
    }

    for (int i = 0; i < k - 1; ++i) {
        heap.pop();
    }

    int ans = 0;
    while (!heap.empty()) {
        ans += heap.top();
        heap.pop();
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}