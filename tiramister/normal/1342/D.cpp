#include <iostream>
#include <vector>

using lint = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> ms(k, 0);
    for (int i = 0; i < n; ++i) {
        int m;
        std::cin >> m;
        ++ms[--m];
    }

    for (int i = k - 2; i >= 0; --i) {
        ms[i] += ms[i + 1];
    }

    std::vector<int> cs(k);
    for (auto& c : cs) std::cin >> c;

    int num = 0;
    for (int i = 0; i < k; ++i) {
        while (cs[i] * num < ms[i]) ++num;
    }

    for (int i = 0; i + 1 < k; ++i) {
        ms[i] -= ms[i + 1];
    }

    std::vector<std::vector<int>> ans(num);
    int it = 0;
    for (int i = k - 1; i >= 0; --i) {
        while (ms[i]--) {
            ans[it].push_back(i);
            if (++it == num) it = 0;
        }
    }

    std::cout << ans.size() << "\n";

    for (const auto& v : ans) {
        std::cout << v.size();
        for (auto x : v) {
            std::cout << " " << x + 1;
        }
        std::cout << "\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}