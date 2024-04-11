#include <iostream>
#include <vector>
#include <string>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> ss(n), ts(m);
    for (auto& s : ss) std::cin >> s;
    for (auto& t : ts) std::cin >> t;

    int q;
    std::cin >> q;
    while (q--) {
        int y;
        std::cin >> y;
        --y;
        std::cout << ss[y % n] << ts[y % m] << std::endl;
    }
    return 0;
}