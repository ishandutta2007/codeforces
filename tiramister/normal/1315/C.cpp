#include <iostream>
#include <vector>
#include <queue>

template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> pos(n * 2, -1);
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        pos[--x] = i;
    }

    std::vector<int> ans(n * 2, -1);
    MinHeap<int> fpos;
    for (int x = 0; x < n * 2; ++x) {
        if (pos[x] != -1) {
            int i = pos[x];
            ans[i * 2] = x;
            fpos.push(i * 2 + 1);
        } else {
            if (fpos.empty()) {
                std::cout << -1 << std::endl;
                return;
            }

            int i = fpos.top();
            fpos.pop();
            ans[i] = x;
        }
    }

    for (auto x : ans) std::cout << x + 1 << " ";
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}