#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> ss(n);
    for (auto& s : ss) std::cin >> s;

    std::string fore;
    for (int i = 0; i < n; ++i) {
        std::string s = ss[i];
        std::reverse(s.begin(), s.end());

        for (int j = 0; j < i; ++j) {
            const std::string& t = ss[j];
            if (s == t) fore += t;
        }
    }
    auto back = fore;
    std::reverse(back.begin(), back.end());

    std::string center;
    for (int i = 0; i < n; ++i) {
        std::string s = ss[i];
        std::reverse(s.begin(), s.end());
        if (ss[i] == s) {
            center = s;
            break;
        }
    }

    std::string ans = fore + center + back;
    std::cout << ans.length() << std::endl
              << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}