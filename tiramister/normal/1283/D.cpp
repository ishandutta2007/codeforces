#include <iostream>
#include <vector>
#include <set>

using lint = long long;

int main() {
    int n, m;
    std::cin >> n >> m;

    std::set<lint> trees, occupied;
    while (n--) {
        lint x;
        std::cin >> x;
        trees.insert(x);
        occupied.insert(x);
    }

    lint sum = 0;
    std::vector<lint> ys;
    for (lint d = 1; m > 0; ++d) {
        std::set<lint> burned;

        for (auto x : trees) {
            bool used = false;

            lint nx;
            nx = x - d;
            if (!occupied.count(nx)) {
                used = true;
                ys.push_back(nx);
                occupied.insert(nx);
                sum += d;
                --m;
            }
            if (m == 0) break;

            nx = x + d;
            if (!occupied.count(nx)) {
                used = true;
                ys.push_back(nx);
                occupied.insert(nx);
                sum += d;
                --m;
            }
            if (m == 0) break;

            if (!used) burned.insert(x);
        }

        for (auto x : burned) trees.erase(x);
    }

    std::cout << sum << std::endl;
    for (auto y : ys) std::cout << y << " ";
    std::cout << std::endl;
    return 0;
}