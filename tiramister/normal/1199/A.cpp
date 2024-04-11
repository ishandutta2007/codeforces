#include <iostream>
#include <vector>

int main() {
    int n, x, y;
    std::cin >> n >> x >> y;

    std::vector<int> as(n);
    for (auto& a : as) std::cin >> a;

    for (int i = 0; i < n; ++i) {
        bool ok = true;
        for (int j = i - x; j <= i + y; ++j) {
            if (j < 0 || j == i || n <= j) continue;
            if (as[i] > as[j]) ok = false;
        }

        if (ok) {
            std::cout << i + 1 << std::endl;
            return 0;
        }
    }

    std::terminate();
    return 0;
}