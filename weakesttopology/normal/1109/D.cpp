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
    int n, m, junk;
    cin >> n >> m >> junk >> junk;
    int N = n + m;
    vector<mint> f(N + 1, 1), inv(N + 1, 1);
    for (int x = 1; x <= N; ++x) {
        f[x] = x * f[x - 1];
        inv[x] = 1 / f[x];
    }
    auto S = [&](int n, int k){ return f[n + k - 1] * inv[n] * inv[k - 1]; };
    mint ans = 0;
    for (int x = 0; x <= n - 2 && x < m; ++x) {
        mint t = (x + 2) * mint(n).power(n - (x + 2) - 1);
        ans += f[n - 2] * inv[n - 2 - x] * S(m - (x + 1), x + 1) * t * mint(m).power(n - (x + 2));
    }
    cout << ans << endl;
    exit(0);
}