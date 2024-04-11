#include <iostream>
#include <algorithm>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    int l = 0;
    for (int r = 1; r < n; ++r) {
        char c;
        std::cin >> c;
        if (c == '0') {
            std::sort(xs.begin() + l, xs.begin() + r);
            l = r;
        }
    }
    std::sort(xs.begin() + l, xs.end());

    bool judge = true;
    for (int i = 0; i + 1 < n; ++i) {
        if (xs[i] > xs[i + 1]) judge = false;
    }
    std::cout << (judge ? "YES" : "NO") << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}