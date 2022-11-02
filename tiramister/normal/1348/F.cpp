#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <tuple>

template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

void print(const std::vector<std::tuple<int, int, int>>& ans) {
    int n = ans.size();
    std::vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        pos[std::get<2>(ans[i])] = i;
    }

    for (auto p : pos) std::cout << p + 1 << " ";
    std::cout << "\n";
}

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::vector<std::pair<int, int>>> rss(n);
    for (int i = 0; i < n; ++i) {
        int l, r;
        std::cin >> l >> r;
        rss[--l].emplace_back(--r, i);
    }

    std::vector<std::tuple<int, int, int>> ans(n);  // (l, r, i)
    MinHeap<std::tuple<int, int, int>> rlque;       // (r, l, i)
    for (int x = 0; x < n; ++x) {
        for (auto [r, i] : rss[x]) {
            rlque.emplace(r, x, i);
        }

        auto [r, l, i] = rlque.top();
        rlque.pop();
        ans[x] = std::make_tuple(l, r, i);
    }

    auto nans = ans;
    MinHeap<std::pair<int, int>> rxque;  // (r, x)
    std::set<std::pair<int, int>> ts;    // (x, r)
    for (int x = 0; x < n; ++x) {
        while (!rxque.empty() && rxque.top().first < x) {
            auto [pr, px] = rxque.top();
            rxque.pop();
            ts.erase(std::make_pair(px, pr));
        }

        auto [l, r, i] = ans[x];

        if (!ts.empty() && (--ts.end())->first >= l) {
            int px = (--ts.end())->first;
            std::swap(nans[x], nans[px]);
            break;
        }

        rxque.emplace(r, x);
        ts.emplace(x, r);
    }

    if (ans == nans) {
        std::cout << "YES\n";
        print(ans);
    } else {
        std::cout << "NO\n";
        print(ans);
        print(nans);
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}