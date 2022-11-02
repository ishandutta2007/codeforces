#include <iostream>
#include <algorithm>
#include <vector>

using lint = long long;

constexpr lint INF = 1LL << 40;

void solve() {
    int n, m;
    std::cin >> n >> m;
    int l = 1 << n;

    std::vector<int> xs(l, 0);
    while (m--) {
        int x;
        std::cin >> x;
        xs[--x] = 1;
    }

    std::vector<std::vector<lint>> segs(l, std::vector<lint>(4, -INF));
    for (int ni = l - 1; ni >= 1; --ni) {
        auto& seg = segs[ni];

        if (ni >= l / 2) {
            int i = (ni - l / 2) * 2;
            int cnt = xs[i] + xs[i + 1];
            if (cnt == 0) {
                seg[0] = 0;
            } else if (cnt == 1) {
                seg[1] = seg[2] = 1;
            } else if (cnt == 2) {
                seg[3] = 1;
            }
            continue;
        }

        const auto &lseg = segs[ni * 2 + 0],
                   &rseg = segs[ni * 2 + 1];

        for (int b1 = 0; b1 < 4; ++b1) {
            for (int b2 = 0; b2 < 4; ++b2) {
                int x = (b1 & 1) + (b2 & 1),
                    y = (b1 >> 1) + (b2 >> 1);

                for (int nx = 0; nx <= std::min(x, 1); ++nx) {
                    if (x - nx > 1) continue;
                    int py = y + (x - nx);

                    for (int ny = 0; ny <= std::min(py, 1); ++ny) {
                        int r = py - ny;
                        if (r > 2) continue;

                        int plus = (x > 0) + (y > 0) + (py > 0);

                        int nb = nx + (ny << 1);
                        seg[nb] = std::max(seg[nb], lseg[b1] + rseg[b2] + plus);
                    }
                }
            }
        }
    }

    lint ans = -INF;
    for (int b = 0; b < 4; ++b) {
        ans = std::max(ans, segs[1][b] + (b > 0));
    }

    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}