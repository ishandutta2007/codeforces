#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void solve() {
    int n, k;
    std::string s;
    std::cin >> n >> k >> s;
    std::sort(s.begin(), s.end());

    int i = 0;
    std::vector<std::string> ans(k);

    for (auto& t : ans) {
        t.push_back(s[i++]);
    }

    if (i < n && s.front() == s[i - 1] && s[i] == s.back()) {
        while (i < n) {
            for (auto& t : ans) {
                t.push_back(s[i++]);
                if (i == n) break;
            }
        }
    } else {
        while (i < n) {
            ans.front().push_back(s[i++]);
        }
    }

    std::cout << *std::max_element(ans.begin(), ans.end()) << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}