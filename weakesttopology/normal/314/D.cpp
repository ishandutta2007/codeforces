#include <bits/stdc++.h>
const int64_t inf = std::numeric_limits<int64_t>::max() / 2;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<int64_t> x(N), y(N);
    for (int i = 0; i < N; ++i) {
        int a, b;
        std::cin >> a >> b;
        x[i] = a + b;
        y[i] = a - b;
    }
    std::vector<int> I(N);
    std::iota(I.begin(), I.end(), 0);
    std::sort(I.begin(), I.end(), [&](int i, int j) { return x[i] < x[j]; });
    auto check = [&](double d) {
        enum Type {enter, leave};
        std::vector<std::tuple<double, int, Type>> events;
        for (auto i : I) {
            events.emplace_back(x[i], i, enter);
        }
        for (auto i : I) {
            events.emplace_back(x[i] + d, i, leave);
        }
        std::inplace_merge(events.begin(), events.begin() + N, events.end());
        std::vector<int64_t> prefmax(2 * N, -inf), prefmin(2 * N, +inf), suffmax(2 * N, -inf), suffmin(2 * N, +inf);
        for (int i = 0; i < 2 * N; ++i) {
            auto [__, j, t] = events[i];
            if (t == leave) {
                prefmin[i] = prefmax[i] = y[j];
            } else {
                if (i > 0) {
                    suffmin[i - 1] = suffmax[i - 1] = y[j];
                }
            }
            if (i) {
                prefmin[i] = std::min(prefmin[i], prefmin[i - 1]);
                prefmax[i] = std::max(prefmax[i], prefmax[i - 1]);
            }
        }
        for (int i = 2 * N - 2; i >= 0; --i) {
            suffmin[i] = std::min(suffmin[i], suffmin[i + 1]);
            suffmax[i] = std::max(suffmax[i], suffmax[i + 1]);
        }
        for (int i = 0; i < 2 * N; ++i) {
            int64_t min = std::min(prefmin[i], suffmin[i]);
            int64_t max = std::max(prefmax[i], suffmax[i]);
            if (max - min <= d) {
                return true;
            }
        }
        return false;
    };
    double L = 0, R = 1e10;
    for (int t = 0; t < 60; ++t) {
        double M = (L + R) / 2;
        check(M) ? R = M : L = M;
    }
    std::cout << std::setprecision(10) << std::fixed;
    std::cout << R / 2 << '\n';
    exit(0);
}