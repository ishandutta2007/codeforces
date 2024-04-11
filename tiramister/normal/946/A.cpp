#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    int ans = 0;
    while (n--) {
        int a;
        std::cin >> a;
        ans += std::abs(a);
    }

    std::cout << ans << std::endl;
    return 0;
}