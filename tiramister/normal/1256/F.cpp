#include <iostream>
#include <algorithm>
#include <string>

bool hasdup(std::string s) {
    auto n = s.length();
    std::sort(s.begin(), s.end());
    s.erase(std::unique(s.begin(), s.end()), s.end());
    return n != s.length();
}

int count(std::string s) {
    int ret = 0;

    bool update = true;
    while (update) {
        update = false;
        for (int i = 0; i + 1 < (int)s.length(); ++i) {
            if (s[i] > s[i + 1]) {
                update = true;
                std::swap(s[i], s[i + 1]);
                ++ret;
            }
        }
    }

    return ret;
}

void solve() {
    int n;
    std::string s, t;
    std::cin >> n >> s >> t;

    for (char c = 'a'; c <= 'z'; ++c) {
        if (std::count(s.begin(), s.end(), c) !=
            std::count(t.begin(), t.end(), c)) {
            std::cout << "NO" << std::endl;
            return;
        }
    }

    if (hasdup(s)) {
        std::cout << "YES" << std::endl;
        return;
    }

    std::cout << (count(s) % 2 == count(t) % 2 ? "YES" : "NO")
              << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}