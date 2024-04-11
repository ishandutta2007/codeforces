#include <iostream>
#include <set>

void solve() {
    int n, x;
    std::cin >> n >> x;

    std::set<int> xs;
    while (n--) {
        int i;
        std::cin >> i;
        xs.insert(i);
    }

    for (int i = 1;; ++i) {
        if (xs.count(i)) continue;
        if (x > 0) {
            --x;
        } else {
            std::cout << i - 1 << std::endl;
            break;
        }
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}