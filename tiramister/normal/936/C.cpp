#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>

void solve() {
    int n;
    std::string s, t;
    std::cin >> n >> s >> t;

    std::vector<int> ans;
    auto ope = [&](int x) {
        ans.push_back(x);

        auto back = s.substr(s.length() - x, x);
        s.resize(s.length() - x);

        std::reverse(back.begin(), back.end());
        s = back + s;
    };

    for (int i = 0; i < n; ++i) {
        std::cerr << s << std::endl;
        int j = 0;
        while (j < n && s[j] != t[i]) ++j;

        if (j >= n - i) {
            std::cout << -1 << std::endl;
            return;
        }

        ope(n - j - 1);
        ope(1);
        ope(n);
    }

    assert(s == t);

    std::cout << ans.size() << std::endl;
    for (auto a : ans) std::cout << a << " ";
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}