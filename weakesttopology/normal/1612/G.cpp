#include <bits/stdc++.h>
constexpr int64_t mod = 1e9 + 7;
constexpr int inf = std::numeric_limits<int>::max(), maxc = 1e6;
int64_t freq_[2 * maxc + 1], offset_[2 * maxc + 1], sumc_[2 * maxc + 1];
int64_t *freq = freq_ + maxc - 1, *offset = offset_ + maxc - 1, *sumc = sumc_ + maxc - 1;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int M;
    std::cin >> M;
    int L = +inf, R = -inf;
    for (int j = 0; j < M; ++j) {
        int c;
        std::cin >> c;
        int l = -c + 1, r = c + 1;
        ++freq[l];
        --freq[r];
        offset[l] += -l;
        offset[r] -= -l;
        sumc[l] += c;
        sumc[r] -= c;
        L = std::min(L, -c + 1);
        R = std::max(R, +c + 1);
    }
    std::vector<int64_t> f(M + 1);
    f[0] = 1;
    for (int n = 1; n <= M; ++n) {
        f[n] = n * f[n - 1] % mod;
    }
    int64_t ways = 1, opt = 0, cnt = 0;
    for (int x = L; x < R; ++x) {
        freq[x + 2] += freq[x];
        offset[x + 2] += offset[x];
        sumc[x + 2] += sumc[x];

        ways = ways * f[freq[x]] % mod;
        int64_t sum_pos = (x * freq[x] + offset[x]) / 2 % mod;
        opt += sum_pos * cnt - (sumc[x] - (sum_pos + freq[x])) % mod * cnt;
        opt %= mod;
        cnt += freq[x];
        cnt %= mod;
    }
    opt = (opt + mod) % mod;
    std::cout << opt << ' ' << ways << '\n';
    exit(0);
}