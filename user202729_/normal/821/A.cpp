#include <iostream>
#include <vector>

int n;

int main() {
    std::cin >> n;
    std::vector<std::vector<int>> lab(n, std::vector<int>(n));
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) std::cin >> lab[r][c];
    }
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            if (lab[r][c] == 1) continue;
            for (int r1 = 0; r1 < n; ++r1) {
                for (int c1 = 0; c1 < n; ++c1) {
                    if (lab[r1][c] + lab[r][c1] == lab[r][c])
                        goto nextcell;
                }
            }
            std::cout << "No\n";
            return 0;
            nextcell:;
        }
    }
    std::cout << "Yes\n";
    return 0;
}