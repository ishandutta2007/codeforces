#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cassert>

template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

using lint = long long;

void solve() {
    int n;
    std::cin >> n;

    int k;
    for (k = 20; n < (1 << k); --k) {}

    std::vector<lint> xs(n);
    for (auto& x : xs) std::cin >> x;
    std::reverse(xs.begin(), xs.end());

    lint ans = 0;

    MinHeap<lint> heap;
    int itr = 0;
    heap.push(xs[itr++]);

    for (int q = 0; q < k; ++q) {
        lint a = heap.top();
        heap.pop();
        if (a < 0) break;

        ans += a;
        int added = (1 << (k - q - 1));
        while (added--) {
            heap.push(xs[itr++]);
        }
    }

    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}