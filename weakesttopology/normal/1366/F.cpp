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
template<typename T>
bool chmax(T& x, T y) { return x < y ? (x = y, true) : false; }
ll sum(ll L, ll R) {
    return R * (R + 1) / 2 - L * (L - 1) / 2;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll q;
    cin >> n >> m >> q;
    vector<array<int, 3>> edges(m);
    for (auto& [u, v, w] : edges) {
        cin >> u >> v >> w;
        --u, --v;
    }
    const ll inf = 0x3f3f3f3f3f3f3f3f;
    vector<ll> dp(n, -inf);
    dp[0] = 0;
    mint ans = 0;
    for (int j = 0; j < m; ++j) {
        vector<ll> dpnxt(n, -inf);
        for (auto e : edges) {
            for (int t : {0, 1}) {
                chmax(dpnxt[e[t]], dp[e[t ^ 1]] + e[2]);
            }
        }
        swap(dp, dpnxt);
        ans += *max_element(begin(dp), end(dp));
    }
    q -= m;
    map<int, ll> best;
    for (auto e : edges) {
        for (int t : {0, 1}) {
            best[e[2]] = max(best[e[2]], dp[e[t]]);
        }
    }
    vector<pair<int, ll>> bestv(begin(best), end(best));
    int k = (int)size(bestv);
    ll taken = 0;
    for (int j = 0; j < k && q > taken; ++j) {
        auto [a, b] = bestv[j];
        ll t = q;
        for (int l = j + 1; l < k; ++l) {
            auto [c, d] = bestv[l];
            t = min(t, (b - d + c - a - 1) / (c - a) - 1);
        }
        if (t > taken) {
            ans += mint(t - taken) * b + mint(sum(taken + 1, t)) * a;
            taken = t;
        }
    }
    cout << ans << endl;
    exit(0);
}