#include <iostream>

void solve() {
    int n;
    std::cin >> n;

    int ans = 0, h = 0;
    while (n--) {
        char c;
        std::cin >> c;

        int nh = h + (c == '(' ? 1 : -1);
        if (h < 0 || nh < 0) ++ans;
        h = nh;
    }

    std::cout << (h != 0 ? -1 : ans) << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}