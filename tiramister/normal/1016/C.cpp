#include <iostream>
#include <vector>

using lint = long long;

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

void solve() {
    int n;
    std::cin >> n;

    auto xss = vec(2, vec(n, 0LL));
    for (auto& xs : xss) {
        for (auto& x : xs) std::cin >> x;
    }

    std::vector<lint> sums(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        sums[i] = sums[i + 1] + xss[0][i] + xss[1][i];
    }

    auto usums = vec(2, vec(n + 1, 0LL));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < 2; ++j) {
            usums[j][i] = usums[j][i + 1] + sums[i + 1] +
                          xss[j][i] * ((n - i) * 2 - 1);
        }
    }

    lint ans = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        ans = std::max(ans, sum + usums[1 - i % 2][i] + sums[i] * i * 2);

        sum += xss[i % 2][i] * i * 2 +
               xss[1 - i % 2][i] * (i * 2 + 1);
    }

    ans = std::max(ans, sum);

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}