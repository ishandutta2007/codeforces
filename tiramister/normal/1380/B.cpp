#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

const std::string hands = "RSP";
const std::string wins = "PRS";

void solve() {
    std::string s;
    std::cin >> s;

    std::vector<int> cnt(3, 0);
    for (int i = 0; i < 3; ++i) {
        cnt[i] = std::count(s.begin(), s.end(), hands[i]);
    }

    int i = std::max_element(cnt.begin(), cnt.end()) - cnt.begin();
    std::cout << std::string(s.length(), wins[i]) << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}