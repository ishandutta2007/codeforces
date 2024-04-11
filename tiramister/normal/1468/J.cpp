#line 1 "combined.cpp"

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

#include <iostream>
#line 71 "combined.cpp"
#include <tuple>

using namespace std;
using lint = long long;
constexpr lint INF = 1LL << 60;

void solve() {
    int n, m;
    lint k;
    cin >> n >> m >> k;

    vector<tuple<lint, int, int>> es(m);
    vector<lint> cs{-INF, INF};
    for (auto& [c, u, v] : es) {
        cin >> u >> v >> c;
        --u, --v;
        cs.push_back(c);
    }
    sort(es.begin(), es.end());

    lint cost = 0;
    atcoder::dsu dsu(n);
    for (auto [c, u, v] : es) {
        if (dsu.same(u, v)) continue;
        dsu.merge(u, v);
        cost += max(0LL, c - k);
    }

    if (cost == 0) {
        sort(cs.begin(), cs.end());

        cost = INF;
        auto it = lower_bound(cs.begin(), cs.end(), k);
        cost = min(cost, *it - k);
        --it;
        cost = min(cost, k - *it);
    }

    cout << cost << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}