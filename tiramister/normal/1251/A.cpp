#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using lint = long long;
using ldouble = long double;

int main() {
    int t;
    std::cin >> t;
    for (int q = 0; q < t; ++q) {
        std::string s;
        std::cin >> s;
        s.push_back('$');

        int len = 0;
        char prev = '*';
        std::set<char> ok;

        for (char c : s) {
            if (c != prev) {
                if (len % 2 != 0) {
                    ok.insert(prev);
                }
                len = 0;
            }
            prev = c;
            ++len;
        }

        for (char c : ok) {
            std::cout << c;
        }
        std::cout << std::endl;
    }
    return 0;
}