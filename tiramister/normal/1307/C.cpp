#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using lint = long long;

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

void solve() {
    std::string s;
    std::cin >> s;

    std::vector<lint> cnt(27, 0);
    cnt[26] = 1;
    auto dp = vec(27, vec(27, 0LL));
    for (char cc : s) {
        int c = cc - 'a';
        for (int d = 0; d < 27; ++d) {
            dp[d][c] += cnt[d];
        }
        ++cnt[c];
    }

    lint ans = 0;
    for (const auto& v : dp) {
        ans = std::max(ans, *std::max_element(v.begin(), v.end()));
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