#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using lint = long long;
using ldouble = long double;

int dsum(lint x) {
    int ret = 0;
    while (x > 0) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

int sumup(lint x, int k) {
    int ret = 0;
    for (int i = 0; i <= k; ++i) {
        ret += dsum(x + i);
    }
    return ret;
}

constexpr int X = 150;
constexpr int M = 1000000;

std::vector<std::vector<int>> table(10, std::vector<int>(X + 1, -1));

void build() {
    for (int x = 0; x <= M; ++x) {
        int sum = 0;
        for (int k = 0; k <= 9; ++k) {
            sum += dsum(x + k);

            if (sum > X) break;
            if (table[k][sum] == -1) table[k][sum] = x;
        }
    }
}

void check() {
    int k;
    std::cin >> k;

    std::vector<lint> ans(X + 1, -1);
    for (auto x = 0; x <= M; ++x) {
        int s = sumup(x, k);
        if (s > X || ans[s] != -1) continue;
        ans[s] = x;
    }

    for (int i = 1; i <= X; ++i) {
        std::cout << i << ": " << ans[i] << "\n";
    }
}

lint solve0(int n) {
    lint ret = n % 9;
    n -= n % 9;

    while (n > 0) {
        ret = ret * 10 + std::min(n, 9);
        n -= std::min(n, 9);
    }
    return ret;
}

lint solve1(int n) {
    if (n % 2 != 0) {
        return solve0((n - 17) / 2) * 10 + 8;
    } else {
        return solve1(n - 9) * 10 + 9;
    }
}

void solve() {
    int n, k;
    std::cin >> n >> k;

    if (k >= 2) {
        std::cout << table[k][n] << "\n";
        return;
    }

    if (table[k][n] != -1 || n < 40) {
        std::cout << table[k][n] << "\n";
        return;
    }

    if (k == 0) {
        std::cout << solve0(n) << "\n";
        return;
    }

    if (k == 1) {
        std::cout << solve1(n) << "\n";
        return;
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    // check();

    build();

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}