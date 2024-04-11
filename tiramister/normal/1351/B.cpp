#include <iostream>
#include <algorithm>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

void solve() {
    auto xss = vec(2, vec(2, 0));
    for (auto& xs : xss) {
        for (auto& x : xs) {
            std::cin >> x;
        }
        std::sort(xs.begin(), xs.end());
    }

    int n = xss[0][1];
    bool ans = xss[1][1] == n;
    if (xss[0][0] + xss[1][0] != n) ans = false;

    std::cout << (ans ? "Yes" : "No") << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}