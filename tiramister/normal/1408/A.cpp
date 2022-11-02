#include <iostream>
#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

void solve() {
    int n;
    std::cin >> n;

    auto xss = vec(n, vec(3, 0));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> xss[j][i];
        }
    }

    int prev = -1, first = -1;
    for (auto& xs : xss) {
        for (auto x : xs) {
            if (prev == x || first == x) continue;

            if (prev != -1) {
                std::cout << " ";
            } else {
                first = x;
            }
            std::cout << x;

            prev = x;
            break;
        }
    }

    std::cout << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}