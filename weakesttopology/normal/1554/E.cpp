#include <bits/stdc++.h>
using namespace std;
template<long long mod>
struct Mint {
    long long x;
    Mint() : x(0) {}
    Mint(long long x_) {
        x = x_ % mod;
        if (x < 0) x += mod;
    }
    Mint& operator+=(Mint rhs) {
        x += rhs.x;
        if (x >= mod) x -= mod;
        return *this;
    }
    Mint& operator-=(Mint rhs) {
        x -= rhs.x;
        if (x < 0) x += mod;
        return *this;
    }
    Mint& operator*=(Mint rhs) {
        x = x * rhs.x % mod;
        return *this;
    }
    Mint& operator/=(Mint rhs) {
        return *this *= rhs.power(-1);
    }
    Mint power(long long p) const {
        p %= mod - 1;
        if (p < 0) p += mod - 1;
        Mint res = 1;
        for (Mint y = *this; p; p >>= 1, y *= y) if (p & 1) res *= y;
        return res;
    }
    Mint operator-() const {
        return Mint() - *this;
    }
    bool operator==(Mint rhs) const { return x == rhs.x; }
    bool operator!=(Mint rhs) const { return x != rhs.x; }
    bool operator<(Mint rhs) const { return x < rhs.x; }
    friend Mint operator+(Mint lhs, Mint rhs) { return lhs += rhs; }
    friend Mint operator-(Mint lhs, Mint rhs) { return lhs -= rhs; }
    friend Mint operator*(Mint lhs, Mint rhs) { return lhs *= rhs; }
    friend Mint operator/(Mint lhs, Mint rhs) { return lhs /= rhs; }
    friend ostream& operator<<(ostream& out, Mint a) { return out << a.x; }
    friend istream& operator>>(istream& in, Mint& a) {
        long long x;
        in >> x;
        a = Mint(x);
        return in;
    }
    inline static const Mint X = [](){
        uniform_int_distribution<long long> unif(1, mod - 1);
        mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());
        return unif(rng);
    }(), Xinv = 1 / X;
};
using mint = Mint<998'244'353>;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> E(n);
        vector<int> deg(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            E[u].push_back(v);
            E[v].push_back(u);
            ++deg[u], ++deg[v];
        }
        vector<int> leaves(n);
        for (int u = 0; u < n; ++u) {
            if (deg[u] > 1) continue;
            for (auto v : E[u]) {
                ++leaves[v];
            }
        }
        vector<int> cost(n);
        for (int x = 2; x < n; ++x) {
            for (int y = x; y < n; y += x) {
                ++cost[y];
            }
        }
        int best = -1, best_cost = 0;
        for (int u = 0; u < n; ++u) {
            if (deg[u] == 1 || leaves[u] < deg[u] - 1) continue;
            int cur_cost = cost[deg[u]] + cost[deg[u] - 1];
            if (best == -1 || cur_cost < best_cost) {
                best = u;
                best_cost = cur_cost;
            }
            break;
        }
        vector<mint> ans(n + 1);
        ans[1] = mint(2).power(n - 1);
        if (best != -1) {
            vector<int> candidates;
            for (int t : {0, 1}) {
                int x = deg[best] - t;
                for (int d = 2; d <= x; ++d) {
                    if (x % d == 0) {
                        candidates.push_back(d);
                    }
                }
            }
            for (auto g : candidates) {
                bool good = true;
                auto dfs = [&](auto& self, int u, int p) -> int {
                    int a = 0;
                    for (auto v : E[u]) {
                        if (v == p) continue;
                        a += self(self, v, u);
                    }
                    if (a % g == 0) {
                        return 1;
                    }
                    else if ((a + 1) % g == 0) {
                        return 0;
                    }
                    else {
                        good = false;
                        return 0;
                    }
                };
                int b = dfs(dfs, 0, -1);
                ans[g] = good && b == 1;
            }
        }
        for (int k = n; k >= 1; --k) {
            for (int x = 2 * k; x <= n; x += k) {
                ans[k] -= ans[x];
            }
        }
        for (int k = 1; k <= n; ++k) {
            cout << ans[k] << "\n "[k < n];
        }
    }
    exit(0);
}