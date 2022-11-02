#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using lint = long long;

lint calc(const std::vector<lint>& xs, bool insert) {
    int n = xs.size();

    std::vector<lint> backmin(n), backmax(n);
    backmin.back() = backmax.back() = xs.back();

    for (int i = n - 2; i >= 0; --i) {
        backmin[i] = std::min(backmin[i + 1], xs[i]);
        backmax[i] = std::max(backmax[i + 1], xs[i]);
    }

    lint ret = backmax.front() - backmin.front();
    if (!insert) return ret + 1;

    lint min = 0, max = 0;
    for (int i = 0; i < n; ++i) {
        min = std::min(min, xs[i]);
        max = std::max(max, xs[i]);

        ret = std::min(ret, std::max(max, backmax[i] - 1) - std::min(min, backmin[i] - 1));
        ret = std::min(ret, std::max(max, backmax[i] + 1) - std::min(min, backmin[i] + 1));
    }

    return ret + 1;
}

void solve() {
    std::string s;
    std::cin >> s;

    std::vector<lint> xs{0}, ys{0};
    for (char c : s) {
        if (c == 'W') {
            ys.push_back(ys.back() + 1);
        } else if (c == 'S') {
            ys.push_back(ys.back() - 1);
        } else if (c == 'D') {
            xs.push_back(xs.back() + 1);
        } else if (c == 'A') {
            xs.push_back(xs.back() - 1);
        }
    }

    std::cout << std::min(calc(xs, true) * calc(ys, false),
                          calc(xs, false) * calc(ys, true))
              << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}