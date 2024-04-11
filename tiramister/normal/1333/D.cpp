#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void solve() {
    int n, k;
    std::string s;
    std::cin >> n >> k >> s;

    int cnt = 0;
    std::vector<std::vector<int>> xss;
    while (true) {
        int i = 0;
        xss.push_back({});

        while (i + 1 < n) {
            if (s.substr(i, 2) == "RL") {
                xss.back().push_back(i);
                ++cnt;

                s[i] = 'L', s[i + 1] = 'R';
                i += 2;

            } else {
                i += 1;
            }
        }

        if (xss.back().empty()) {
            xss.pop_back();
            break;
        }
    }

    std::vector<std::vector<int>> ans;
    while (!xss.empty() &&
           (int)xss.size() + (int)ans.size() < k) {
        auto p = xss.back().back();
        xss.back().pop_back();

        ans.push_back({p});
        if (xss.back().empty()) xss.pop_back();
    }

    while (!xss.empty()) {
        ans.push_back(xss.back());
        xss.pop_back();
    }

    if (k != (int)ans.size()) {
        std::cout << -1 << std::endl;
        return;
    }

    std::reverse(ans.begin(), ans.end());

    for (const auto& v : ans) {
        std::cout << v.size() << " ";
        for (auto i : v) std::cout << i + 1 << " ";
        std::cout << "\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}