#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

using lint = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::pair<lint, lint>> ps(n);
    for (auto& p : ps) std::cin >> p.second >> p.first;
    std::sort(ps.rbegin(), ps.rend());

    lint ans = 0;
    MinHeap<lint> heap;
    lint tsum = 0;

    for (auto [b, t] : ps) {
        tsum += t;
        heap.push(t);

        if ((int)heap.size() > k) {
            tsum -= heap.top();
            heap.pop();
        }

        ans = std::max(ans, tsum * b);
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}