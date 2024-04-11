#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    for (int i = 30; i >= 0; --i) {
        int cnt = 0, pj = -1;
        for (int j = 0; j < n; ++j) {
            if ((xs[j] >> i) & 1) {
                ++cnt;
                pj = j;
            }
        }

        if (cnt == 1) {
            std::swap(xs[0], xs[pj]);
            break;
        }
    }

    for (auto x : xs) std::cout << x << " ";
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}