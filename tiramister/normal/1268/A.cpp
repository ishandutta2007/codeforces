#include <iostream>
#include <string>
#include <cassert>

int main() {
    int n, k;
    std::string s;
    std::cin >> n >> k >> s;

    std::string t = s;
    for (int i = k; i < n; ++i) {
        t[i] = t[i - k];
    }

    if (t >= s) {
        std::cout << t.length() << std::endl
                  << t << std::endl;
        return 0;
    }

    t = s;
    ++t[k - 1];
    for (int i = k - 1; i >= 0; --i) {
        if (t[i] <= '9') break;
        t[i] = '0';
        ++t[i - 1];
    }

    for (int i = k; i < n; ++i) {
        t[i] = t[i - k];
    }

    assert(t >= s);
    std::cout << t.length() << std::endl
              << t << std::endl;
    return 0;
}