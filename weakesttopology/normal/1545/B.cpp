#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<ll mod>
struct Mint {
    ll x;
    Mint() : x(0) {}
    Mint(ll x) : x((x %= mod) < 0 ? x + mod : x) { }
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
    Mint operator-() const { return Mint() - *this; }
    bool operator==(Mint rhs) const { return x == rhs.x; }
    bool operator!=(Mint rhs) const { return x != rhs.x; }
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
using mint = Mint<998244353>;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        s.push_back('0');
        ++n;
        vector<int> p(n);
        int cnt[2]{};
        for (int i = 0; i < n; ++i) {
            p[i] = s[i] - '0';
            if (i > 0) p[i] ^= p[i - 1];
            ++cnt[s[i] - '0'];
        }
        int cnt_odd = 0;
        for (int i = 0, last = 0; i < n; ++i) {
            if (s[i] == '1') continue;
            cnt_odd += last ^ p[i];
            last = p[i];
        }
        vector<mint> f(n + 1, 1), inv(n + 1, 1);
        for (int k = 1; k <= n; ++k) {
            f[k] = k * f[k - 1];
            inv[k] = 1 / f[k];
        }
        auto C = [&](int n, int k) {
            return k > n ? 0 : f[n] * inv[k] * inv[n - k];
        };
        auto S = [&](int n, int k) {
            return C(n + k - 1, k - 1);
        };
        assert((cnt[1] - cnt_odd) % 2 == 0);
        mint ans = S((cnt[1] - cnt_odd) / 2, cnt[0]);
        cout << ans << '\n';
    }
    exit(0);
}