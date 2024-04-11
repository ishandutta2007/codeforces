#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }
constexpr int INF = 1 << 30;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    std::vector<int> sums(1 << n, 0);
    for (int b = 0; b < (1 << n); ++b) {
        auto& sum = sums[b];
        for (int i = 0; i < n; ++i) {
            if ((b >> i) & 1) sum += xs[i];
        }
    }

    auto li = vec(n + 1, vec(1 << n, -1));
    for (int pi = 0; pi <= n; ++pi) {
        for (int b = 0; b < (1 << n); ++b) {
            for (int i = pi; i < n; ++i) {
                if ((b >> i) & 1) {
                    li[pi][b] = i;
                    break;
                }
            }
        }
    }

    auto dp = vec(n + 1, vec(n, vec(1 << n, INF)));
    auto rev = vec(n + 1, vec(n, vec(1 << n, std::make_pair(-1, -1))));

    for (int b = 1; b < (1 << n); ++b) {
        int sum = sums[b];
        int i = li[0][b];
        dp[1][i][b] = sum;
        rev[1][i][b] = std::make_pair(b, -1);
    }

    for (int c = 1; c < n; ++c) {
        for (int pi = 0; pi < n; ++pi) {
            for (int b = 0; b < (1 << n); ++b) {
                if (dp[c][pi][b] == INF) continue;

                int invb = ((1 << n) - 1) & (~b);

                for (int nb = invb; nb >= 1; nb = (nb - 1) & invb) {
                    int sum = sums[nb];
                    if (sum <= dp[c][pi][b]) continue;

                    int i = li[pi + 1][nb];
                    if (i == -1 || dp[c + 1][i][b | nb] < sum) continue;

                    dp[c + 1][i][b | nb] = sum;
                    rev[c + 1][i][b | nb] = std::make_pair(nb, pi);
                }
            }
        }
    }

    int mc = -1, mi = -1;
    int b = (1 << n) - 1;
    for (int c = n; c >= 0; --c) {
        for (int i = 0; i < n; ++i) {
            if (dp[c][i][b] < INF) {
                mc = c;
                mi = i;
                break;
            }
        }
        if (mc != -1) break;
    }

    std::vector<std::pair<int, int>> ans;

    std::set<int> idxs;
    for (int i = 0; i < n; ++i) idxs.insert(i);
    auto getidx = [&](int i) {
        return std::count_if(idxs.begin(), idxs.end(),
                             [&](int j) { return j <= i; });
    };

    while (mc > 0) {
        auto [nb, pi] = rev[mc][mi][b];

        for (int i = 0; i < n; ++i) {
            if (((nb >> i) & 1) && i != mi) {
                ans.emplace_back(getidx(i), getidx(mi));
                idxs.erase(i);
            }
        }

        --mc;
        b ^= nb;
        mi = pi;
    }

    std::cout << ans.size() << "\n";
    for (auto p : ans) {
        std::cout << p.first << " " << p.second << "\n";
    }
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}