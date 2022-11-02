#include <iostream>
#include <vector>
#include <string>

using lint = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    std::vector<bool> ok(26, false);
    while (k--) {
        char c;
        std::cin >> c;
        ok[c - 'a'] = true;
    }

    std::vector<lint> arr{0};
    for (char c : s) {
        if (ok[c - 'a']) {
            ++arr.back();
        } else {
            arr.push_back(0);
        }
    }

    lint ans = 0;
    for (auto x : arr) {
        ans += x * (x + 1) / 2;
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