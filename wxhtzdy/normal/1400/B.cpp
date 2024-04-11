#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int p, f;
    std::cin >> p >> f;

    int cnts, cntw;
    std::cin >> cnts >> cntw;

    int s, w;
    std::cin >> s >> w;

    if (s > w) {
        std::swap(s, w);
        std::swap(cnts, cntw);
    }

    int ans = 0;
    for (int i = 0; i <= cnts; i++) {
        if (i * s > p) break;

        int nans = i;
        int tw = std::min((p - i * s) / w, cntw);
        nans += tw;

        int ncnts = cnts - i, ncntw = cntw - tw;
        int x = std::min(f / s, ncnts);
        int nf = f - x * s;
        int y = std::min(nf / w, ncntw);
        nans += x + y;

        ans = std::max(ans, nans);
    }

    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}