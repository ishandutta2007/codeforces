#include <iostream>
#include <vector>

using lint = long long;

int n;
std::vector<lint> xs, ds;

void init() {
    int nmax = (1 << 20);
    xs.resize(nmax, 0);
    ds.resize(nmax, 1);

    for (int v = 2; v < nmax; ++v) {
        ds[v] = ds[v / 2] + 1;
    }
}

int dfs(int v) {
    int vl = v * 2 + 0,
        vr = v * 2 + 1;

    if (vl >= n ||
        (xs[vl] == 0 && xs[vr] == 0)) {
        return v;
    }

    return dfs(xs[vl] > xs[vr] ? vl : vr);
}

void solve() {
    int h, g;
    std::cin >> h >> g;

    n = (1 << h);
    for (int i = 1; i < n; ++i) std::cin >> xs[i];

    std::vector<lint> ans;
    for (int r = 1; r < n; ++r) {
        if (xs[r] == 0) continue;
        while (true) {
            int v = dfs(r);
            if (ds[v] <= g) break;

            ans.push_back(r);
            auto prev = xs[v];
            xs[v] = 0;

            while (v != r) {
                v /= 2;
                std::swap(xs[v], prev);
            }
        }
    }

    lint sum = 0;
    for (int i = 1; i < (1 << g); ++i) sum += xs[i];

    std::cout << sum << "\n";
    for (auto a : ans) std::cout << a << " ";
    std::cout << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    init();

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}