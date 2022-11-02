#include <iostream>
#include <string>

void solve() {
    int n;
    std::cin >> n;

    std::string a, b;
    a.reserve(n), b.reserve(n);

    bool leading = true, diff = false;

    while (n--) {
        char c;
        std::cin >> c;

        int d = c - '0';

        if (diff) {
            a.push_back('0');
            b.push_back(c);

        } else {
            if (d == 0) {
                if (leading) {
                    a.push_back('2');
                    b.push_back('1');
                    diff = true;
                } else {
                    a.push_back('0');
                    b.push_back('0');
                }
            } else if (d == 1) {
                if (leading) {
                    a.push_back('2');
                    b.push_back('2');
                } else {
                    a.push_back('1');
                    b.push_back('0');
                    diff = true;
                }
            } else {
                a.push_back('1');
                b.push_back('1');
            }
        }

        leading = false;
    }

    std::cout << a << "\n"
              << b << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}