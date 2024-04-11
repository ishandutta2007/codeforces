#include <iostream>

void solve() {
    int n;
    std::cin >> n;

    int sum = 0, ans = 0;
    while (n--) {
        int x;
        std::cin >> x;
        if (x == 0) {
            ++ans;
            ++x;
        }
        sum += x;
    }

    if (sum == 0) ++ans;
    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}