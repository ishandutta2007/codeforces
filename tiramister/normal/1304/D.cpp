#include <iostream>
#include <vector>
#include <string>

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;

    int l;

    l = 0;
    while (l < n) {
        int r = l;
        while (r < n && s[r] == '<') ++r;
        for (int i = l; i <= r; ++i) {
            std::cout << n - r + (i - l) << " ";
        }
        l = r + 1;
    }
    std::cout << std::endl;

    l = 0;
    while (l < n) {
        int r = l;
        while (r < n && s[r] == '>') ++r;
        for (int i = l; i <= r; ++i) {
            std::cout << r - (i - l) + 1 << " ";
        }
        l = r + 1;
    }
    std::cout << std::endl;
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