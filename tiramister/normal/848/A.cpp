#include <iostream>
#include <string>

void solve() {
    int k;
    std::cin >> k;

    std::string s;
    for (char c = 'a'; c <= 'z'; ++c) {
        int m = 1000;
        while (m * (m - 1) / 2 > k) --m;

        k -= m * (m - 1) / 2;
        while (m--) s.push_back(c);
    }

    std::cout << s << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}