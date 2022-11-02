#include <iostream>

int main() {
    int q;
    std::cin >> q;

    while (q--) {
        int n, k;
        std::cin >> n >> k;

        int ans = n / k * k + std::min(k / 2, n % k);
        std::cout << ans << std::endl;
    }
    return 0;
}