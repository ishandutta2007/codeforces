#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using lint = long long;

template <class T>
using MaxHeap = std::priority_queue<T>;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, lint>> ps(n);
    for (int i = 0; i < n; ++i) std::cin >> ps[i].first;
    for (int i = 0; i < n; ++i) std::cin >> ps[i].second;
    std::sort(ps.begin(), ps.end());

    MaxHeap<lint> heap;
    lint hsum = 0, ans = 0;
    int idx = 0, x = 0;
    while (true) {
        if (heap.empty()) {
            if (idx == n) break;
            x = ps[idx].first;
        }

        while (idx < n && x == ps[idx].first) {
            heap.push(ps[idx].second);
            hsum += ps[idx].second;
            ++idx;
        }

        hsum -= heap.top();
        heap.pop();
        ans += hsum;
        ++x;
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