#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void solve() {
    int n, k;
    std::string s;
    std::cin >> n >> k >> s;

    std::vector<std::pair<int, int>> ans;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') continue;

        int j;
        for (j = i + 1; j < n; ++j) {
            if (s[j] == '(') break;
        }
        if (j == n) break;

        ans.emplace_back(i, j);
        std::reverse(s.begin() + i, s.begin() + j + 1);
    }

    int match = 1;
    int l = 1, r = n / 2;
    while (match < k) {
        std::reverse(s.begin() + l, s.begin() + r + 1);
        ans.emplace_back(l, r);
        l += 2, ++r;
        ++match;
    }

    std::cout << ans.size() << "\n";
    for (auto p : ans) std::cout << p.first + 1 << " " << p.second + 1 << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}