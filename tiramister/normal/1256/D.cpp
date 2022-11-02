#include <iostream>
#include <vector>

using lint = long long;

void solve() {
    int n;
    lint k;
    std::cin >> n >> k;

    std::vector<lint> ps;
    for (int i = 0; i < n; ++i) {
        char c;
        std::cin >> c;
        if (c == '0') ps.push_back(i);
    }

    int head = -1, it = 0;
    while (k > 0 && it < (int)ps.size()) {
        ++head;
        lint d = std::min(k, ps[it] - head);
        ps[it] -= d;
        k -= d;
        ++it;
    }

    it = 0;
    for (int i = 0; i < n; ++i) {
        if (it < (int)ps.size() && ps[it] == i) {
            std::cout << 0;
            ++it;
        } else {
            std::cout << 1;
        }
    }
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}