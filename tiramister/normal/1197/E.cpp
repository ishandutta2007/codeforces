#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

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

template <class T>
std::map<T, int> compress(std::vector<T>& v) {
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    std::map<T, int> rev;
    for (int i = 0; i < (int)v.size(); ++i) rev[v[i]] = i;
    return rev;
}

constexpr int MOD = 1e9 + 7;
using mint = ModInt<MOD>;

constexpr int INF = 1 << 30;

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> ps(n);
    std::vector<int> xs;
    xs.reserve(n * 2 + 1);

    int imax = 0;
    for (auto& p : ps) {
        std::cin >> p.first >> p.second;
        imax = std::max(imax, p.second);
        xs.push_back(p.first);
        xs.push_back(p.second);
    }
    xs.push_back(0);

    auto revx = compress(xs);
    int m = xs.size();

    std::vector<std::vector<std::pair<int, int>>> graph(m);
    for (int v = 0; v + 1 < m; ++v) {
        graph[v].emplace_back(v + 1, xs[v + 1] - xs[v]);
    }
    for (auto p : ps) {
        graph[revx[p.second]].emplace_back(revx[p.first], 0);
    }

    std::vector<int> min(m, INF);
    std::vector<mint> pat(m, 0);
    min[0] = 0;
    pat[0] = 1;
    for (int v = 0; v < m; ++v) {
        for (auto [nv, c] : graph[v]) {
            int nc = min[v] + c;

            if (nc < min[nv]) {
                min[nv] = nc;
                pat[nv] = 0;
            }

            if (nc == min[nv]) {
                pat[nv] += pat[v];
            }
        }
    }

    int tmin = INF;
    mint ans = 0;
    for (int i = 0; i < m; ++i) {
        if (xs[i] <= imax) continue;

        if (min[i] < tmin) {
            tmin = min[i];
            ans = 0;
        }

        if (min[i] == tmin) {
            ans += pat[i];
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}