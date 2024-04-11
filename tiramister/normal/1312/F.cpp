#include <iostream>
#include <vector>
#include <set>
#include <map>

const std::vector<std::vector<int>> nxt{{0, 1, 2}, {0, 2}, {0, 1}};

using lint = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> xs(3);
    for (auto& x : xs) std::cin >> x;

    lint l, r;

    std::vector<std::vector<int>> gs(1, std::vector<int>(3, 0));
    std::map<std::vector<std::vector<int>>, int> pats;

    std::set<int> ss;
    std::vector<int> ngs(3);
    for (int t = 1;; ++t) {
        for (int i = 0; i < 3; ++i) {
            ss.clear();
            for (auto j : nxt[i]) {
                ss.insert(gs[std::max(0, t - xs[j])][j]);
            }

            for (int g = 0;; ++g) {
                if (!ss.count(g)) {
                    ngs[i] = g;
                    break;
                }
            }
        }
        gs.push_back(ngs);

        if (t >= 5) {
            std::vector<std::vector<int>> lasts(gs.end() - 5, gs.end());

            if (pats.count(lasts)) {
                l = pats[lasts];
                r = t;
                break;
            }
            pats[lasts] = t;
        }
    }

    auto grundy = [&](lint x, int i) {
        if (x <= 0) return 0;
        if (x >= r) x = (x - l) % (r - l) + l;
        return gs[x][i];
    };

    std::vector<lint> ys(n);
    int acc = 0;
    for (auto& y : ys) {
        std::cin >> y;
        acc ^= grundy(y, 0);
    }

    int ans = 0;
    if (acc != 0) {
        for (auto y : ys) {
            acc ^= grundy(y, 0);
            for (int i = 0; i < 3; ++i) {
                if ((acc ^ grundy(y - xs[i], i)) == 0) ++ans;
            }
            acc ^= grundy(y, 0);
        }
    }
    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();

    return 0;
}