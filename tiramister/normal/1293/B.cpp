#include <iostream>
#include <iomanip>

using ldouble = long double;

void solve() {
    int n;
    std::cin >> n;

    ldouble ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += ldouble(1) / i;
    }
    std::cout << std::fixed << std::setprecision(12) << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}