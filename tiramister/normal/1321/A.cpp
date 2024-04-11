#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> rs(n), bs(n);
    for (auto& r : rs) std::cin >> r;
    for (auto& b : bs) std::cin >> b;

    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        if (rs[i] == 1 && bs[i] == 0) ++x;
        if (rs[i] == 0 && bs[i] == 1) ++y;
    }

    std::cout << (x == 0 ? -1 : (x + y) / x) << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}