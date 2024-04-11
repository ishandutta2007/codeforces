#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using ldouble = double;

// y1 > 0, y2 < 0
ldouble intersect(ldouble x1, ldouble y1, ldouble x2, ldouble y2) {
    ldouble r = y1 / (y1 - y2);
    return x1 + (x2 - x1) * r;
}

void solve() {
    ldouble sy, sl, sr;
    std::cin >> sy >> sl >> sr;

    ldouble t = sr - sl;

    int n;
    std::cin >> n;

    std::vector<std::pair<ldouble, ldouble>> segs(n);
    std::vector<ldouble> ls(n);
    for (int i = 0; i < n; ++i) {
        int l, r;
        std::cin >> l >> r;
        segs[i].first = ls[i] = l;
        segs[i].second = r;
    }

    std::vector<ldouble> sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        sum[i + 1] = sum[i] + segs[i].second - segs[i].first;
    }

    auto shade = [&](ldouble x) -> ldouble {
        int i = std::lower_bound(ls.begin(), ls.end(), x) - ls.begin();

        ldouble ret = 0;
        if (i > 0 && x < segs[i - 1].second) {
            ret += x - segs[i - 1].first;
            --i;
        }

        ret += sum[i];
        return ret;
    };

    int q;
    std::cin >> q;
    while (q--) {
        ldouble x, y;
        {
            int xx, yy;
            std::cin >> xx >> yy;
            x = xx, y = yy;
        }

        ldouble l = intersect(x, y, sl, sy),
                r = intersect(x, y, sr, sy);
        std::cout << (shade(r) - shade(l)) / (r - l) * t << "\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);

    solve();

    return 0;
}