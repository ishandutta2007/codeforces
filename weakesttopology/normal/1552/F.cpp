#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<ll mod>
struct Mint {
    ll x;
    Mint() : x(0) {}
    Mint(ll x_) {
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
    Mint power(ll p) const {
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
        ll x;
        in >> x;
        a = Mint(x);
        return in;
    }
    inline static const Mint X = [](){
        uniform_int_distribution<ll> unif(1, mod - 1);
        mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());
        return unif(rng);
    }(), Xinv = 1 / X;
};
using mint = Mint<998'244'353>;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> x(n), y(n), s(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> s[i];
    }
    vector<mint> addcnt(n);
    mint cnt = 1, ans = x[n - 1] + 1;
    for (int i = n - 1; i >= 0; --i) {
        mint adding = cnt - (s[i] == 0);
        cnt += adding;
        ans += adding * (x[i] - y[i]);
        int j = int(lower_bound(begin(x), end(x), y[i]) - begin(x));
        addcnt[j] -= adding;
        cnt += addcnt[i];
    }
    cout << ans << '\n';
    exit(0);
}