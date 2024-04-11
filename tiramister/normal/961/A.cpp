#include <iostream>
#include <algorithm>
#include <vector>

void solve() {
    int n, q;
    std::cin >> n >> q;

    std::vector<int> cnt(n, 0);
    while (q--) {
        int x;
        std::cin >> x;
        ++cnt[--x];
    }

    std::cout << *std::min_element(cnt.begin(), cnt.end()) << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}