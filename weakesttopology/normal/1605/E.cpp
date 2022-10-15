#include <bits/stdc++.h>
using cpx = std::complex<int64_t>;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<int> a(N + 1), b(N + 1);
    for (int i = 1; i <= N; ++i) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= N; ++i) {
        std::cin >> b[i];
    }
    std::vector<cpx> dp(N + 1);
    dp[1] = cpx(-a[1], 1);
    for (int i = 1; i <= N; ++i) {
        if (i != 1) {
            dp[i] += b[i] - a[i];
        }
        for (int j = 2 * i; j <= N; j += i) {
            dp[j] -= dp[i];
        }
    }
    int Q;
    std::cin >> Q;
    std::vector<int> x(Q);
    for (int q = 0; q < Q; ++q) {
        std::cin >> x[q];
    }
    std::vector<int> qs(Q);
    std::iota(qs.begin(), qs.end(), 0);
    std::sort(qs.begin(), qs.end(), [&](int q1, int q2) { return x[q1] < x[q2]; });
    std::vector<cpx> f(Q + 1);
    auto update = [&](int l, int r, cpx add) {
        f[l] += add;
        f[r] -= add;
    };
    for (int i = 1; i <= N; ++i) {
        if (dp[i].imag() > 0) {
            int m = std::upper_bound(qs.begin(), qs.end(), 0, [&](int dummy, int q) { return dp[i].imag() * x[q] + dp[i].real() > 0; }) - qs.begin();
            update(0, m, -dp[i]);
            update(m, Q, +dp[i]);
        } else if (dp[i].imag() < 0) {
            int m = std::upper_bound(qs.begin(), qs.end(), 0, [&](int dummy, int q) { return dp[i].imag() * x[q] + dp[i].real() < 0; }) - qs.begin();
            update(0, m, +dp[i]);
            update(m, Q, -dp[i]);
        } else {
            update(0, Q, std::abs(dp[i].real()));
        }
    }
    std::partial_sum(f.begin(), f.end(), f.begin());
    std::vector<int64_t> ans(Q);
    for (int i = 0; i < Q; ++i) {
        int q = qs[i];
        ans[q] = f[i].imag() * x[q] + f[i].real();
    }
    for (int q = 0; q < Q; ++q) {
        std::cout << ans[q] << '\n';
    }
    exit(0);
}