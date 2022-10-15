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
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> l(m), r(m), x(m);
    vector<vector<int>> J(n + 1);
    for (int j = 0; j < m; ++j) {
        cin >> l[j] >> r[j] >> x[j];
        J[r[j]].push_back(j);
    }
    mint ans = 1;
    for (int b = 0; b < k; ++b) {
        vector<int> cnt(n + 2);
        for (int j = 0; j < m; ++j) {
            if (x[j] >> b & 1) {
                ++cnt[l[j]], --cnt[r[j] + 1];
            }
        }
        mint tot = 1;
        vector<mint> dp(n + 1);
        int lb = 0;
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            cnt[i + 1] += cnt[i];
            if (cnt[i] == 0) {
                dp[i] = tot;
                tot *= 2;
            }
            for (auto j : J[i]) {
                if (~x[j] >> b & 1) {
                    while (lb < l[j]) {
                        tot -= dp[lb++];
                    }
                }
            }
        }
        ans *= tot;
    }
    cout << ans << endl;
    exit(0);
}