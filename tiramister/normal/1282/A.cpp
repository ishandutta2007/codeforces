#include <iostream>

int main() {
    int q;
    std::cin >> q;

    while (q--) {
        int s, t, c, ri;
        std::cin >> s >> t >> c >> ri;
        if (s > t) std::swap(s, t);

        int l = c - ri, r = c + ri;
        int len = t - s;
        l = std::max(l, s);
        r = std::min(r, t);
        len -= std::max(0, r - l);
        std::cout << len << std::endl;
    }
    return 0;
}