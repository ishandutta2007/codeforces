#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

template <class T>
std::map<T, int> compress(std::vector<T>& v) {
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    std::map<T, int> rev;
    for (int i = 0; i < (int)v.size(); ++i) rev[v[i]] = i;
    return rev;
}

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> ls(n), rs(n), xs;
    for (int i = 0; i < n; ++i) {
        std::cin >> ls[i] >> rs[i];
        ++rs[i];
        xs.push_back(ls[i]);
        xs.push_back(rs[i]);
    }

    auto rev = compress(xs);
    m = rev.size();

    std::vector<std::vector<int>> jsegs(m), lsegs(m);
    for (int i = 0; i < n; ++i) {
        int l = rev[ls[i]],
            r = rev[rs[i]];
        jsegs[l].push_back(i);
        for (int j = l + 1; j < r; ++j) {
            lsegs[j].push_back(i);
        }
    }

    auto dp = vec(m, vec(1 << k, 0));

    for (int i = 0; i < m - 1; ++i) {
        int jsz = jsegs[i].size(),
            lsz = lsegs[i].size(),
            nlsz = lsegs[i + 1].size();

        for (int bl = 0; bl < (1 << lsz); ++bl) {
            for (int bj = 0; bj < (1 << jsz); ++bj) {
                int cnt = __builtin_popcount(bj) + __builtin_popcount(bl);
                int score = dp[i][bl] + (cnt & 1) * (xs[i + 1] - xs[i]);

                int nbl = 0;
                for (int j = 0; j < nlsz; ++j) {
                    int id = lsegs[i + 1][j];

                    bool contain = false;
                    for (int l = 0; l < jsz; ++l) {
                        if (((bj >> l) & 1) && jsegs[i][l] == id) {
                            contain = true;
                        }
                    }

                    for (int l = 0; l < lsz; ++l) {
                        if (((bl >> l) & 1) && lsegs[i][l] == id) {
                            contain = true;
                        }
                    }

                    if (contain) nbl |= (1 << j);
                }

                dp[i + 1][nbl] = std::max(dp[i + 1][nbl], score);
            }
        }
    }

    std::cout << dp[m - 1][0] << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}