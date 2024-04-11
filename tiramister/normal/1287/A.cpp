#include <iostream>
#include <string>

int main() {
    int q;
    std::cin >> q;

    while (q--) {
        int n;
        std::string s;
        std::cin >> n >> s;

        s.push_back('A');
        while (s.front() != 'A') s.erase(s.begin());

        int cont = 0, ans = 0;
        for (char c : s) {
            ++cont;
            if (c == 'A') cont = 0;
            ans = std::max(ans, cont);
        }

        std::cout << ans << std::endl;
    }
    return 0;
}