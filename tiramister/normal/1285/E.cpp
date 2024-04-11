#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

template <class T>
std::map<T, int> compress(std::vector<T>& v) {
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    std::map<T, int> rev;
    for (int i = 0; i < (int)v.size(); ++i) {
        rev[v[i]] = i;
    }
    return rev;
}

constexpr int INF = 1 << 30;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> ls(n), rs(n), xs{-INF, INF};
    for (int i = 0; i < n; ++i) {
        std::cin >> ls[i] >> rs[i];
        xs.push_back(ls[i]);
        xs.push_back(rs[i]);
    }

    // compress and doubling
    auto rev = compress(xs);
    for (auto& l : ls) l = rev[l] * 2;
    for (auto& r : rs) r = rev[r] * 2;
    int m = xs.size() * 2;

    // imos
    std::vector<int> cnt(m, 0);
    for (int i = 0; i < n; ++i) {
        ++cnt[ls[i]];
        --cnt[rs[i] + 1];
    }
    for (int i = 1; i < m; ++i) cnt[i] += cnt[i - 1];

    // # of segments in original united segments
    int total = 0;
    for (int i = 0; i < m - 1; ++i) {
        if (cnt[i] == 0 && cnt[i + 1] > 0) ++total;
    }

    std::vector<int> inccnt(m - 1, 0);
    // cnt[i] == 1 && cnt[i + 1] > 1
    for (int i = 0; i < m - 1; ++i) {
        if (i > 0) inccnt[i] = inccnt[i - 1];
        if (cnt[i] == 1 && cnt[i + 1] > 1) ++inccnt[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int inc = total;
        if (ls[i] < rs[i]) inc += inccnt[rs[i] - 1] - inccnt[ls[i] - 1];
        if (cnt[ls[i] - 1] == 0 && cnt[ls[i]] == 1) --inc;  // left end
        if (cnt[rs[i]] == 1 && cnt[rs[i] + 1] > 0) ++inc;   // right end
        ans = std::max(ans, inc);
    }
    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) solve();
    return 0;
}