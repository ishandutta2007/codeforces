#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

int main() {
    int q;
    std::cin >> q;
    while (q--) {
        std::string s;
        std::cin >> s;

        std::vector<std::queue<char>> parity(2);
        for (char c : s) {
            parity[c % 2].push(c);
        }

        while (!parity[0].empty() || !parity[1].empty()) {
            int idx;
            if (parity[0].empty()) {
                idx = 1;
            } else if (parity[1].empty()) {
                idx = 0;
            } else {
                idx = (parity[0].front() < parity[1].front() ? 0 : 1);
            }

            std::cout << parity[idx].front();
            parity[idx].pop();
        }
        std::cout << std::endl;
    }
    return 0;
}