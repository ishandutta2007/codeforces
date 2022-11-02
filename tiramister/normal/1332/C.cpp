#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void solve() {
    int n, k;
    std::string s;
    std::cin >> n >> k >> s;

    std::vector<std::vector<int>> cnt(k, std::vector<int>(26, 0));
    for (int i = 0; i < n; ++i) {
        int j = i % k;
        if (k - 1 - j < j) j = k - 1 - j;
        ++cnt[j][s[i] - 'a'];
    }

    int ans = n;
    for (const auto& v : cnt) {
        ans -= *std::max_element(v.begin(), v.end());
    }

    std::cout << ans << std::endl;
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