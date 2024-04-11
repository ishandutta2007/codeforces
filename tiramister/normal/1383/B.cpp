#include <iostream>
#include <vector>

bool judge(int z, int o) {
    if ((o - 1) % 4 == 0) {
        return true;
    } else {
        return z % 2 == 1;
    }
}

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    for (int k = 30; k >= 0; --k) {
        int z = 0, o = 0;
        for (auto x : xs) {
            if ((x >> k) & 1) {
                ++o;
            } else {
                ++z;
            }
        }

        if (o % 2 != 0) {
            std::cout << (judge(z, o) ? "WIN" : "LOSE") << "\n";
            return;
        }
    }

    std::cout << "DRAW\n";
    return;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}