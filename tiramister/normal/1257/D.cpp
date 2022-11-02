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

void solve() {
    std::vector<int> zs;

    int n;
    std::cin >> n;

    std::vector<int> xs(n);
    for (auto& x : xs) {
        std::cin >> x;
        zs.push_back(x);
    }

    int m;
    std::cin >> m;

    std::vector<int> ys(m), ss(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> ys[i] >> ss[i];
        zs.push_back(ys[i]);
    }

    auto rev = compress(zs);
    for (auto& x : xs) x = rev[x];
    for (auto& y : ys) y = rev[y];
    int l = zs.size();

    std::vector<int> maxs(l, 0);
    for (int i = 0; i < m; ++i) {
        maxs[ys[i]] = std::max(maxs[ys[i]], ss[i]);
    }
    for (int k = l - 2; k >= 0; --k) {
        maxs[k] = std::max(maxs[k], maxs[k + 1]);
    }

    int ans = 1, cont = 1, maxx = 0;
    for (int i = 0; i < n; ++i) {
        maxx = std::max(maxx, xs[i]);

        if (maxs[maxx] < cont) {
            if (cont == 1) {
                std::cout << -1 << "\n";
                return;
            } else {
                maxx = 0;
                cont = 0;
                ++ans;
                --i;
            }
        }
        ++cont;
    }
    std::cout << ans << "\n";
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