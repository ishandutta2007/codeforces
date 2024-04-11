#include <iostream>

using lint = long long;

constexpr lint HMAX = 1LL << 32;

void solve() {
    lint n, h;
    std::cin >> n >> h;

    lint ok = 0, ng = HMAX;
    while (ng - ok > 1) {
        lint mid = (ok + ng) / 2;

        lint sum = 0;
        if (mid <= h) {
            sum += mid * (mid + 1) / 2;
        } else {
            lint len = mid + h - 1;
            auto half = len / 2;

            sum += half * (half + 1);
            if (len % 2 == 1) sum += half + 1;

            sum -= h * (h - 1) / 2;
        }

        if (sum < n) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    std::cout << ng << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}