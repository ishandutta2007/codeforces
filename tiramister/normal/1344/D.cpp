#include <iostream>
#include <algorithm>
#include <vector>

using lint = long long;
constexpr lint INF = 1 << 30;
constexpr lint LINF = 1LL << 62;

void solve() {
    int n;
    lint m;
    std::cin >> n >> m;

    std::vector<lint> xs(n);
    for (auto& x : xs) std::cin >> x;

    lint ok = -LINF, ng = INF;
    // at least m items are chosen when the lower bound is ok
    while (ng - ok > 1) {
        auto mid = (ok + ng) / 2;

        lint cnt = 0;
        for (auto x : xs) {
            lint yok = -1, yng = x;
            // you can choose yok-th item

            while (yng - yok > 1) {
                lint y = (yok + yng) / 2;
                if (x - 3 * y * y - 3 * y - 1 >= mid) {
                    yok = y;
                } else {
                    yng = y;
                }
            }

            cnt += yok + 1;
        }

        if (cnt >= m) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    std::vector<lint> ans(n, 0);
    std::vector<int> just;

    for (int i = 0; i < n; ++i) {
        auto x = xs[i];
        lint yok = -1, yng = x;
        // you can choose yok-th item

        while (yng - yok > 1) {
            lint y = (yok + yng) / 2;
            if (x - y * y * 3 - y * 3 - 1 >= ok) {
                yok = y;
            } else {
                yng = y;
            }
        }

        ans[i] = yok + 1;
        m -= ans[i];

        if (ans[i] >= 0 &&
            x - yok * yok * 3 - yok * 3 - 1 == ok) {
            just.push_back(i);
        }
    }

    while (m < 0) {
        int i = just.back();
        just.pop_back();
        --ans[i];
        ++m;
    }

    for (auto a : ans) std::cout << a << " ";
    std::cout << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}