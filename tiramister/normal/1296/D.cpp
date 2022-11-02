#include <iostream>
#include <queue>

template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

using lint = long long;

void solve() {
    int n;
    lint a, b, k;
    std::cin >> n >> a >> b >> k;

    MinHeap<lint> heap;
    while (n--) {
        lint h;
        std::cin >> h;
        h %= a + b;
        if (h == 0) h += a + b;

        h -= a;
        heap.push(h <= 0 ? 0 : (h + a - 1) / a);
    }

    int ans = 0;
    while (!heap.empty()) {
        k -= heap.top();
        heap.pop();

        if (k < 0) break;
        ++ans;
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