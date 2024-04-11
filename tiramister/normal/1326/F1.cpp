#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using lint = long long;

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

int bitrev(int b, int n) {
    int ret = 0;
    while (n--) {
        ret <<= 1;
        ret += (b & 1);
        b >>= 1;
    }
    return ret;
}

void solve() {
    int n;
    std::cin >> n;

    auto graph = vec(n, vec(n, 0));
    for (auto& v : graph) {
        for (auto& x : v) {
            char c;
            std::cin >> c;
            x = c - '0';
        }
    }

    int fk = (n - 1) / 2;
    auto fdp = vec(n, vec(1 << n, vec(0, 0LL)));

    for (auto& v : fdp) {
        for (int b = 0; b < (1 << n); ++b) {
            if (__builtin_popcount(b) > fk) continue;
            v[b].assign(1 << __builtin_popcount(b), 0LL);
        }
        v[0][0] = 1;
    }

    for (int b = 0; b < (1 << n); ++b) {
        for (int v = 0; v < n; ++v) {
            if ((b >> v) & 1) continue;

            int k = __builtin_popcount(b);
            if (k >= fk) break;

            int nb = b | (1 << v);
            for (int u = 0; u < n; ++u) {
                if ((nb >> u) & 1) continue;
                int c = graph[v][u];

                for (int s = 0; s < (1 << k); ++s) {
                    fdp[u][nb][s | (c << k)] += fdp[v][b][s];
                }
            }
        }
    }

    int bk = n - 1 - fk;
    auto bdp = vec(n, vec(1 << n, vec(0, 0LL)));

    for (auto& v : bdp) {
        for (int b = 0; b < (1 << n); ++b) {
            if (__builtin_popcount(b) > bk) continue;
            v[b].assign(1 << __builtin_popcount(b), 0LL);
        }
        v[0][0] = 1;
    }

    for (int b = 0; b < (1 << n); ++b) {
        for (int v = 0; v < n; ++v) {
            if ((b >> v) & 1) continue;

            int k = __builtin_popcount(b);
            if (k >= bk) continue;

            int nb = b | (1 << v);
            for (int u = 0; u < n; ++u) {
                if ((nb >> u) & 1) continue;
                int c = graph[v][u];

                for (int s = 0; s < (1 << k); ++s) {
                    bdp[u][nb][s | (c << k)] += bdp[v][b][s];
                }
            }
        }
    }

    std::vector<lint> ans(1 << (n - 1), 0LL);
    for (int b = 0; b < (1 << n); ++b) {
        if (__builtin_popcount(b) != fk) continue;

        for (int v = 0; v < n; ++v) {
            if ((b >> v) & 1) continue;

            int cb = ~b & ((1 << n) - 1);
            cb -= 1 << v;

            for (int sb = 0; sb < (1 << bk); ++sb) {
                int sbr = bitrev(sb, bk);
                for (int sf = 0; sf < (1 << fk); ++sf) {
                    int s = sf | (sbr << fk);

                    ans[s] += fdp[v][b][sf] * bdp[v][cb][sb];
                }
            }
        }
    }

    for (auto a : ans) std::cout << a << " ";
    std::cout << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}