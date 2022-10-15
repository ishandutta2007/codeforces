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
constexpr ll mod = 1e9 + 7;
using mint = Mint<mod>;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, l;
    cin >> n >> m >> l;
    --l;
    if (m < n) {
        cout << 0 << endl;
        exit(0);
    }
    vector<vector<mint>> dp(n + 1, vector<mint>(n + 1, 0));
    dp[0][0] = 1;
    for (int j = 0; j < m; ++j) {
        auto dpnxt = dp;
        if (j == l) {
            for (auto& v : dpnxt) fill(begin(v), end(v), 0);
        }
        for (int x = 0; x <= n; ++x) {
            for (int y = 0; y <= x; ++y) {
                // open
                if (x < n) dpnxt[x + 1][y + 1] += dp[x][y];
                // close
                if (j != l && y > 0) dpnxt[x][y - 1] += dp[x][y];
                // open and close
                if (x < n && y > 0) dpnxt[x + 1][y] += dp[x][y];
            }
            // open and close of length 1
            if (x < n) dpnxt[x + 1][0] += dp[x][0];
        }
        swap(dp, dpnxt);
    }
    mint ans = dp[n][0];
    for (int x = 1; x <= n; ++x) ans *= x;
    cout << ans << endl;
    exit(0);
}