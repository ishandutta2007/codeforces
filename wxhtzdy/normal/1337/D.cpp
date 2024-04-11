#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int nr, ng, nb;
    std::cin >> nr >> ng >> nb;

    std::vector<int> r(nr);
    for (int i = 0; i < nr; i++) {
        std::cin >> r[i];
    }
    std::vector<int> g(ng);
    for (int i = 0; i < ng; i++) {
        std::cin >> g[i];
    }
    std::vector<int> b(nb);
    for (int i = 0; i < nb; i++) {
        std::cin >> b[i];
    }

    std::sort(r.begin(), r.end());
    std::sort(g.begin(), g.end());
    std::sort(b.begin(), b.end());

    int x = 0, y = 0;
    i64 ans = 2e18;
    for (int i = 0; i < nr; i++) {
        while (x + 1 < ng && g[x + 1] <= r[i]) x++;
        while (y + 1 < nb && b[y + 1] <= r[i]) y++;

        std::vector<int> red = {g[x]};
        if (x + 1 < ng) red.push_back(g[x + 1]);

        std::vector<int> blue = {b[y]};
        if (y + 1 < nb) blue.push_back(b[y + 1]);

        for (i64 A : red) {
            for (i64 B : blue) {
                ans = std::min(ans, (A - r[i]) * (A - r[i]) + (B - r[i]) * (B - r[i]) + (A - B) * (A - B));
            }
        }
    }

    std::swap(r, g);
    std::swap(nr, ng);

    x = 0, y = 0;
    for (int i = 0; i < nr; i++) {
        while (x + 1 < ng && g[x + 1] <= r[i]) x++;
        while (y + 1 < nb && b[y + 1] <= r[i]) y++;

        std::vector<int> red = {g[x]};
        if (x + 1 < ng) red.push_back(g[x + 1]);

        std::vector<int> blue = {b[y]};
        if (y + 1 < nb) blue.push_back(b[y + 1]);

        for (i64 A : red) {
            for (i64 B : blue) {
                ans = std::min(ans, (A - r[i]) * (A - r[i]) + (B - r[i]) * (B - r[i]) + (A - B) * (A - B));
            }
        }
    }

    std::swap(r, b);
    std::swap(nr, nb);

    x = 0, y = 0;
    for (int i = 0; i < nr; i++) {
        while (x + 1 < ng && g[x + 1] <= r[i]) x++;
        while (y + 1 < nb && b[y + 1] <= r[i]) y++;

        std::vector<int> red = {g[x]};
        if (x + 1 < ng) red.push_back(g[x + 1]);

        std::vector<int> blue = {b[y]};
        if (y + 1 < nb) blue.push_back(b[y + 1]);

        for (i64 A : red) {
            for (i64 B : blue) {
                ans = std::min(ans, (A - r[i]) * (A - r[i]) + (B - r[i]) * (B - r[i]) + (A - B) * (A - B));
            }
        }
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