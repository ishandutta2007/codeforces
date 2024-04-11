#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void solve() {
    std::string s;
    std::cin >> s;

    int n = s.length();

    int ans = n + 1;
    std::vector<int> cnt(3, 0);
    int r = 0;
    for (int l = 0; l < n; ++l) {
        while (r < n && std::any_of(cnt.begin(), cnt.end(),
                                    [](auto x) { return x == 0; })) {
            ++cnt[s[r++] - '1'];
        }

        if (std::any_of(cnt.begin(), cnt.end(),
                        [](auto x) { return x == 0; })) break;

        ans = std::min(ans, r - l);
        --cnt[s[l] - '1'];
    }

    std::cout << (ans > n ? 0 : ans) << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}