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
void solve() {
    int n;
    cin >> n;
    vector<int> p(n), I(n);
    for (auto& x : I) {
        cin >> x;
        --x;
    }
    for (int i = 0; i < n; ++i) {
        cin >> p[I[i]];
        --p[I[i]];
    }
    mint ans = 1;
    vector<bool> vis(n);
    for (int u = 0; u < n; ++u) {
        if (vis[u]) continue;
        ans *= 2;
        for (int v = u; not vis[v]; v = p[v]) vis[v] = true;
    }
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    exit(0);
}