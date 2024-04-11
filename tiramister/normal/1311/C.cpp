#include <iostream>
#include <vector>
#include <string>

using lint = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<lint>> cnt(n + 1, std::vector<lint>(26, 0));
    for (int i = 1; i <= n; ++i) {
        cnt[i] = cnt[i - 1];
        char c;
        std::cin >> c;
        ++cnt[i][c - 'a'];
    }

    std::vector<lint> ans(26, 0);
    while (m--) {
        int i;
        std::cin >> i;
        for (int k = 0; k < 26; ++k) {
            ans[k] += cnt[i][k];
        }
    }

    for (int k = 0; k < 26; ++k) {
        ans[k] += cnt[n][k];
    }

    for (auto a : ans) std::cout << a << " ";
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