#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

using ldouble = double;

ldouble get() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n;
    ldouble h;
    cin >> n;
    h = get();

    vector<pair<ldouble, ldouble>> ps(n);
    for (auto& [x, y] : ps) x = get(), y = get();
    reverse(ps.begin(), ps.end());

    {
        auto [ox, oy] = ps.front();
        oy += h;

        for (auto& [x, y] : ps) {
            x -= ox, y -= oy;
        }
    }

    ldouble ans = 0;

    auto [px, py] = ps.front();
    for (int i = 0; i + 1 < n; ++i) {
        auto [sx, sy] = ps[i];
        auto [gx, gy] = ps[i + 1];

        if (px * gy - gx * py > 0) continue;
        cerr << i << "\n";

        ldouble ng = 0, ok = 1;
        for (int q = 0; q < 30; ++q) {
            auto t = (ok + ng) / 2;
            auto x = sx * (1 - t) + gx * t,
                 y = sy * (1 - t) + gy * t;

            if (px * y - x * py > 0) {
                ng = t;
            } else {
                ok = t;
            }
        }

        ans += hypot(gx - sx, gy - sy) * (1 - ok);
        px = gx, py = gy;
    }

    cout << ans << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    solve();

    return 0;
}