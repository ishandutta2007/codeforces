#include <iostream>
#include <vector>

int main() {
    int q;
    std::cin >> q;

    while (q--) {
        int n;
        std::vector<int> ks(2);
        std::cin >> n >> ks[0] >> ks[1];
        std::vector<int> max(2, 0);
        for (int i = 0; i < 2; ++i) {
            while (ks[i]--) {
                int a;
                std::cin >> a;
                max[i] = std::max(max[i], a);
            }
        }

        std::cout << (max[0] > max[1] ? "YES" : "NO") << std::endl;
    }
    return 0;
}