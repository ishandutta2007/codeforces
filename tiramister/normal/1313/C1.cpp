#include <iostream>
#include <algorithm>
#include <vector>

using lint = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<lint> xs(n);
    for (auto& x : xs) std::cin >> x;

    std::vector<lint> fore(n), back(n);

    lint sum = 0;
    std::vector<std::pair<lint, int>> cnt;
    for (int i = 0; i < n; ++i) {
        int num = 1;
        while (!cnt.empty() && cnt.back().first > xs[i]) {
            sum -= cnt.back().first * cnt.back().second;
            num += cnt.back().second;
            cnt.pop_back();
        }

        sum += xs[i] * num;
        cnt.emplace_back(xs[i], num);
        fore[i] = sum;
    }

    sum = 0;
    cnt.clear();
    for (int i = n - 1; i >= 0; --i) {
        int num = 1;
        while (!cnt.empty() && cnt.back().first > xs[i]) {
            sum -= cnt.back().first * cnt.back().second;
            num += cnt.back().second;
            cnt.pop_back();
        }

        sum += xs[i] * num;
        cnt.emplace_back(xs[i], num);
        back[i] = sum;
    }

    lint ans = -1, idx = -1;
    for (int i = 0; i < n; ++i) {
        lint score = fore[i] + back[i] - xs[i];
        if (score > ans) {
            ans = score;
            idx = i;
        }
    }

    std::vector<lint> ys(n);
    lint min = xs[idx];
    for (int i = idx; i >= 0; --i) {
        min = std::min(min, xs[i]);
        ys[i] = min;
    }

    min = xs[idx];
    for (int i = idx; i < n; ++i) {
        min = std::min(min, xs[i]);
        ys[i] = min;
    }

    for (auto y : ys) std::cout << y << " ";
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}