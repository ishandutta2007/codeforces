#include "bits/stdc++.h"
const int inf = std::numeric_limits<int>::max() / 3;
std::vector<int> operator+(const std::vector<int>& p, const std::vector<int>& q) {
    int N = p.size();
    std::vector<int> r(N);
    for (int i = 0; i < N; ++i) {
        r[i] = p[q[i]];
    }
    return r;
}
std::vector<int> tau(int N, int i, int j) {
    std::vector<int> p(N);
    std::iota(p.begin(), p.end(), 0);
    std::swap(p[i], p[j]);
    return p;
};
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M, K;
    std::cin >> N >> M >> K;
    std::vector<int> s(K), t(K);
    int smask = 0, tmask = 0;
    for (int j = 0; j < K; ++j) {
        char c;
        std::cin >> c;
        s[j] = c - '0';
        smask |= s[j] << j;
    }
    for (int j = 0; j < K; ++j) {
        char c;
        std::cin >> c;
        t[j] = c - '0';
        tmask |= t[j] << j;
    }
    std::vector<int> dps(1 << K, +inf), dpt(1 << K, -inf), p(K), a(N), b(N);
    dpt[tmask] = dps[smask] = 0;
    std::iota(p.begin(), p.end(), 0);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i] >> b[i];
        --a[i], --b[i];
        p = p + tau(K, a[i], b[i]);
        int nsmask = 0, ntmask = 0;
        for (int j = 0; j < K; ++j) {
            nsmask |= s[j] << p[j];
            ntmask |= t[j] << p[j];
        }
        dps[nsmask] = std::min(dps[nsmask], i + 1);
        dpt[ntmask] = i + 1;
    }
    for (int j = 0; j < K; ++j) {
        for (int mask = 0; mask < (1 << K); ++mask) {
            if (mask >> j & 1) {
                int nmask = mask ^ (1 << j);
                dps[nmask] = std::min(dps[nmask], dps[mask]);
                dpt[nmask] = std::max(dpt[nmask], dpt[mask]);
            }
        }
    }
    int best = 0;
    for (int mask = 0; mask < (1 << K); ++mask) {
        if (dps[mask] + M <= dpt[mask] && __builtin_popcount(mask) > __builtin_popcount(best)) {
            best = mask;
        }
    }
    int l = dps[best], r = dpt[best];
    for (int i = l; i < r; ++i) {
        std::swap(s[a[i]], s[b[i]]);
    }
    int ans = 0;
    for (int j = 0; j < K; ++j) {
        ans += s[j] == t[j];
    }
    std::cout << ans << '\n' << l + 1 << ' ' << r << '\n';
    exit(0);
}