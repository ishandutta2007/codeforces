#include <iostream>
#include <vector>
#include <bitset>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

constexpr int INF = 1 << 29;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    for (auto& x : xs) {
        char c;
        std::cin >> c;
        x = (c == 'R');
    }

    auto dp = vec(4, vec(4, INF));
    for (int b = 0; b < 4; ++b) {
        auto& cost = dp[b][b];
        cost = 0;
        for (int i = 0; i < 2; ++i) {
            if (((b >> i) & 1) != xs[1 - i]) ++cost;
        }
    }

    for (int i = 2; i < n; ++i) {
        auto ndp = vec(4, vec(4, INF));

        for (int pb = 0; pb < 4; ++pb) {
            for (int nc = 0; nc < 2; ++nc) {
                int nb = ((pb << 1) | nc);
                if (nb == 0 || nb == 7) continue;
                nb &= 3;

                int cost = (xs[i] != nc);

                for (int fb = 0; fb < 4; ++fb) {
                    ndp[fb][nb] = std::min(ndp[fb][nb], dp[fb][pb] + cost);
                }
            }
        }

        std::swap(dp, ndp);
    }

    int ans = INF;
    for (int fb = 0; fb < 4; ++fb) {
        for (int pb = 0; pb < 4; ++pb) {
            int b = (pb << 2) | fb;

            bool judge = true;
            for (int s = 0; s < 2; ++s) {
                bool same = true;
                for (int i = 0; i < 2; ++i) {
                    if (((b >> (s + i + 0)) & 1) !=
                        ((b >> (s + i + 1)) & 1)) same = false;
                }
                if (same) judge = false;
            }

            if (!judge) continue;
            ans = std::min(ans, dp[fb][pb]);
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}