#include <iostream>
#include <algorithm>
#include <vector>

template <int MOD>
struct ModInt {
    using lint = long long;
    int val;

    // constructor
    ModInt(lint v = 0) : val(v % MOD) {
        if (val < 0) val += MOD;
    };

    // unary operator
    ModInt operator+() const { return ModInt(val); }
    ModInt operator-() const { return ModInt(MOD - val); }
    ModInt inv() const { return this->pow(MOD - 2); }

    // arithmetic
    ModInt operator+(const ModInt& x) const { return ModInt(*this) += x; }
    ModInt operator-(const ModInt& x) const { return ModInt(*this) -= x; }
    ModInt operator*(const ModInt& x) const { return ModInt(*this) *= x; }
    ModInt operator/(const ModInt& x) const { return ModInt(*this) /= x; }
    ModInt pow(lint n) const {
        auto x = ModInt(1);
        auto b = *this;
        while (n > 0) {
            if (n & 1) x *= b;
            n >>= 1;
            b *= b;
        }
        return x;
    }

    // compound assignment
    ModInt& operator+=(const ModInt& x) {
        if ((val += x.val) >= MOD) val -= MOD;
        return *this;
    }
    ModInt& operator-=(const ModInt& x) {
        if ((val -= x.val) < 0) val += MOD;
        return *this;
    }
    ModInt& operator*=(const ModInt& x) {
        val = lint(val) * x.val % MOD;
        return *this;
    }
    ModInt& operator/=(const ModInt& x) { return *this *= x.inv(); }

    // compare
    bool operator==(const ModInt& b) const { return val == b.val; }
    bool operator!=(const ModInt& b) const { return val != b.val; }

    // I/O
    friend std::istream& operator>>(std::istream& is, ModInt& x) noexcept { return is >> x.val; }
    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) noexcept { return os << x.val; }
};

constexpr int MOD = 1e9 + 7;
using mint = ModInt<MOD>;

template <class Cost = int>
struct Edge {
    int src, dst;
    Cost cost;
    Edge(int src = -1, int dst = -1, Cost cost = 1)
        : src(src), dst(dst), cost(cost){};

    bool operator<(const Edge<Cost>& e) const { return this->cost < e.cost; }
    bool operator>(const Edge<Cost>& e) const { return this->cost > e.cost; }
};

template <class Cost = int>
struct Graph {
    std::vector<std::vector<Edge<Cost>>> graph;

    Graph(int n = 0) : graph(n) {}

    void span(bool direct, int src, int dst, Cost cost = 1) {
        graph[src].emplace_back(src, dst, cost);
        if (!direct) graph[dst].emplace_back(dst, src, cost);
    }

    int size() const { return graph.size(); }
    void clear() { graph.clear(); }
    void resize(int n) { graph.resize(n); }

    std::vector<Edge<Cost>>& operator[](int v) { return graph[v]; }
    std::vector<Edge<Cost>> operator[](int v) const { return graph[v]; }
};

using lint = long long;
constexpr lint INF = 1LL << 60;

void solve() {
    int n, m, q;
    std::cin >> n >> m >> q;
    ++q;
    // t = 0, ..., q-1

    Graph<lint> graph(n);
    while (m--) {
        int u, v;
        lint w;
        std::cin >> u >> v >> w;
        graph.span(false, --u, --v, w);
    }

    std::vector<lint> dist(n, -INF);
    dist[0] = 0;
    auto ndist = dist;
    mint ans = 0;

    for (int i = 0; i < n + 10 && q > 0; ++i, --q) {
        ans += *std::max_element(dist.begin(), dist.end());

        std::fill(ndist.begin(), ndist.end(), -INF);
        for (int v = 0; v < n; ++v) {
            for (auto e : graph[v]) {
                ndist[e.dst] = std::max(ndist[e.dst], dist[v] + e.cost);
            }
        }
        dist = ndist;
    }

    std::vector<std::pair<lint, lint>> ps;
    for (int v = 0; v < n; ++v) {
        for (auto e : graph[v]) {
            ps.emplace_back(dist[v], e.cost);
        }
    }

    // t = 0, ..., q-1
    while (q > 0) {
        auto [b, a] = *std::max_element(ps.begin(), ps.end());
        lint ok = 0, ng = q;
        // t <= ok -> at+b is maximum

        while (ng - ok > 1) {
            lint t = (ok + ng) / 2;
            lint max = 0;
            for (auto [bb, aa] : ps) {
                max = std::max(max, aa * t + bb);
            }

            if (max <= a * t + b) {
                ok = t;
            } else {
                ng = t;
            }
        }

        auto nxt = ng;
        // t < nxt -> at+b is maximum

        ans += mint(nxt) * (nxt - 1) / 2 * a + mint(nxt) * b;
        for (auto& p : ps) p.first += p.second * nxt;
        q -= nxt;
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}