#include <iostream>
#include <vector>
#include <queue>
#include <set>

constexpr int T = 5000;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::set<int>> ls(T), rs(T);
    for (int i = 0; i < n; ++i) {
        int l, r;
        std::cin >> l >> r;
        ls[--l].insert(i);
        rs[--r].insert(i);
    }

    std::vector<int> ans(n, -1);
    std::queue<int> que;
    for (int t = 0; t < T; ++t) {
        for (auto i : ls[t]) que.push(i);

        if (!que.empty()) {
            int i = que.front();
            que.pop();
            ans[i] = t;
        }

        std::queue<int> nque;
        while (!que.empty()) {
            int i = que.front();
            que.pop();
            if (!rs[t].count(i)) nque.push(i);
        }
        std::swap(que, nque);
    }

    for (auto a : ans) std::cout << a + 1 << " ";
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