#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    std::vector<int> ans(n), xs;
    for (int i = 0; i < n; ++i) {
        int c = s[i] - 'a';

        int idx;
        for (idx = 0; idx < (int)xs.size(); ++idx) {
            if (xs[idx] <= c) break;
        }

        ans[i] = idx;
        if (idx == (int)xs.size()) xs.push_back(c);
        xs[idx] = c;
    }

    if (xs.size() > 2) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
        for (auto a : ans) std::cout << a;
        std::cout << std::endl;
    }
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}