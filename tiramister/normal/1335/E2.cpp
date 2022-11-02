#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

template <class T>
using MaxHeap = std::priority_queue<T>;

template <class T>
std::map<T, int> compress(std::vector<T>& v) {
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    std::map<T, int> rev;
    for (int i = 0; i < (int)v.size(); ++i) rev[v[i]] = i;
    return rev;
}

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    auto nxs = xs;
    auto revx = compress(nxs);
    for (auto& x : xs) x = revx[x];

    const int X = revx.size();

    std::vector<int> ocnt(X, 0);
    for (auto x : xs) ++ocnt[x];

    int ans = 0;

    for (int x = 0; x < X; ++x) {
        std::vector<int> cnt = ocnt;
        MaxHeap<std::pair<int, int>> heap;

        for (int y = 0; y < X; ++y) {
            heap.emplace(cnt[y], y);
        }

        int l = 0, r = n - 1;
        for (int i = 0;; ++i) {
            while (cnt[heap.top().second] != heap.top().first) {
                int y = heap.top().second;
                heap.pop();
                heap.emplace(cnt[y], y);
            }

            ans = std::max(ans, i * 2 + heap.top().first);

            while (l < n && xs[l] != x) {
                --cnt[xs[l]];
                ++l;
            }
            while (r >= 0 && xs[r] != x) {
                --cnt[xs[r]];
                --r;
            }

            if (r <= l) break;
            cnt[x] -= 2;
            ++l, --r;
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}