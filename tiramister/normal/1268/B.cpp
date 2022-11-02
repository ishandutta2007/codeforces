#include <iostream>
#include <vector>

using lint = long long;

int main() {
    int n;
    std::cin >> n;

    std::vector<lint> cnt(2, 0);
    for (int i = 0; i < n; ++i) {
        lint a;
        std::cin >> a;
        int less = a / 2;
        cnt[i % 2] += a - less;
        cnt[1 - i % 2] += less;
    }

    std::cout << std::min(cnt[0], cnt[1]) << std::endl;
    return 0;
}