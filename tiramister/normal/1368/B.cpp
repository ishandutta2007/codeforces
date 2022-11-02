#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using lint = long long;

const std::string cf = "codeforces";

void solve() {
    lint n;
    std::cin >> n;

    std::vector<lint> cnt(10, 1);
    lint prod = 1;
    while (prod < n) {
        for (auto& c : cnt) {
            prod /= c;
            ++c;
            prod *= c;
            if (prod >= n) break;
        }
    }

    for (int i = 0; i < 10; ++i) {
        while (cnt[i]--) {
            std::cout << cf[i];
        }
    }
    std::cout << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}