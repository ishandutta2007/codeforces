#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;

    int max = -1, cnt = 0;
    for (int i = 1; i <= k + 1; ++i) {
        std::cout << "?";
        for (int j = 1; j <= k + 1; ++j) {
            if (i == j) continue;
            std::cout << " " << j;
        }
        std::cout << std::endl;

        int idx, val;
        std::cin >> idx >> val;
        if (val > max) {
            max = val;
            cnt = 0;
        }
        if (val == max) cnt++;
    }

    std::cout << "! " << cnt << std::endl;
    return 0;
}