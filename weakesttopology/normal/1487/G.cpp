#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<ll mod>
struct Mint {
    ll x;
    Mint(ll x = 0) : x((x %= mod) < 0 ? x + mod : x) { }
    Mint& operator+=(Mint rhs) { return (x += rhs.x) >= mod ? x -= mod : 0, *this; }
    Mint& operator-=(Mint rhs) { return (x -= rhs.x) < 0 ? x += mod : 0, *this; }
    Mint& operator*=(Mint rhs) { return (x *= rhs.x) %= mod, *this; }
    Mint& operator/=(Mint rhs) { return *this *= rhs.power(-1); }
    Mint power(ll p) const {
        p %= mod - 1;
        if (p < 0) p += mod - 1;
        Mint res = 1;
        for (Mint y = *this; p; p >>= 1, y *= y) if (p & 1) res *= y;
        return res;
    }
    bool operator==(Mint rhs) const { return x == rhs.x; }
    bool operator<(Mint rhs) const { return x < rhs.x; }
    friend Mint operator+(Mint lhs, Mint rhs) { return lhs += rhs; }
    friend Mint operator-(Mint lhs, Mint rhs) { return lhs -= rhs; }
    friend Mint operator*(Mint lhs, Mint rhs) { return lhs *= rhs; }
    friend Mint operator/(Mint lhs, Mint rhs) { return lhs /= rhs; }
    friend ostream& operator<<(ostream& out, Mint a) { return out << a.x; }
    friend istream& operator>>(istream& in, Mint& a) {
        ll x;
        in >> x;
        a = Mint(x);
        return in;
    }
};
constexpr ll mod = 998244353;
using mint = Mint<mod>;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    const int K = 26;
    int c[K];
    for (int x = 0; x < K; ++x) {
        cin >> c[x];
    }
    auto solve1 = [&]() {
        vector<array<array<mint, 2>, 2>> dp(n + 1);
        int cnt[2] = {1, K - 1};
        for (int x = 0; x < K; ++x) {
            for (int y = 0; y < K; ++y) {
                int c = (x == 0) + (y == 0);
                dp[c][!!x][!!y] += 1;
            }
        }
        for (int l = 3; l <= n; ++l) {
            vector<array<array<mint, 2>, 2>> dpnxt(n + 1);
            for (int k = 0; k < n; ++k) {
                for (int t : {0, 1}) {
                    mint tot = 0;
                    for (int s : {0, 1}) tot += dp[k][s][t];
                    for (int s : {0, 1}) {
                        dpnxt[k + (s == 0)][t][s] = cnt[s] * tot - dp[k][s][t];
                    }
                }
            }
            swap(dp, dpnxt);
        }
        mint res = 0;
        for (int x = 0; x < K; ++x) {
            for (int k = c[x] + 1; k <= n; ++k) {
                for (int s : {0, 1}) {
                    for (int t : {0, 1}) {
                        res += dp[k][s][t];
                    }
                }
            }
        }
        return res;
    };
    auto solve2 = [&]() {
        int m = (n + 1) / 2 + 1;
        vector<vector<array<array<mint, 3>, 3>>> dp(m + 1, vector<array<array<mint, 3>, 3>>(m + 1));
        int cnt[3] = {1, 1, K - 2};
        for (int x = 0; x < K; ++x) {
            for (int y = 0; y < K; ++y) {
                int c0 = (x == 0) + (y == 0);
                int c1 = (x == 1) + (y == 1);
                dp[c0][c1][min(x, 2)][min(y, 2)] += 1;
            }
        }
        for (int l = 3; l <= n; ++l) {
            vector<vector<array<array<mint, 3>, 3>>> dpnxt(m + 1, vector<array<array<mint, 3>, 3>>(m + 1));
            for (int k = 0; k < m; ++k) {
                for (int j = 0; j < m; ++j) {
                    for (int t : {0, 1, 2}) {
                        mint tot = 0;
                        for (int s : {0, 1, 2}) tot += dp[k][j][s][t];
                        for (int s : {0, 1, 2}) {
                            dpnxt[k + (s == 0)][j + (s == 1)][t][s] += cnt[s] * tot - dp[k][j][s][t];
                        }
                    }
                }
            }
            swap(dp, dpnxt);
        }
        vector<vector<int>> p(n + 2, vector<int>(n + 2));
        for (int x = 0; x < K; ++x) {
            for (int y = x + 1; y < K; ++y) {
                ++p[c[x] + 1][c[y] + 1];
            }
        }
        for (int k = 0; k <= m; ++k) {
            for (int j = 0; j <= m; ++j) {
                p[k][j + 1] += p[k][j];
            }
        }
        mint res = 0;
        for (int k = 0; k <= m; ++k) {
            for (int j = 0; j <= m; ++j) {
                p[k + 1][j] += p[k][j];
                for (int s : {0, 1, 2}) {
                    for (int t : {0, 1, 2}) {
                        res += p[k][j] * dp[k][j][s][t];
                    }
                }
            }
        }
        return res;
    };
    mint ans = K * K * mint(K - 1).power(n - 2) - solve1() + solve2();
    cout << ans << endl;
    exit(0);
}