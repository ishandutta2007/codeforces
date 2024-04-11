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
auto sieve(int N) {
    vector<int> lp(N + 1, 0), pr;
    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) pr.push_back(lp[i] = i);
        for (auto p : pr) {
            if (p > lp[i] || i * p > N) break;
            lp[i * p] = p;
        }
    }
    return pair(lp, pr);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    const int amax = 2e5;
    auto [lp, pr] = sieve(amax);
    int n, q;
    cin >> n >> q;
    vector<map<int, int>> f(n);
    map<int, priority_queue<pair<int, int>>> pq;
    map<int, int> freq;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        while (a > 1) {
            int p = lp[a], &e = f[i][p];
            while (a % p == 0) ++e, a /= p;
            pq[p].emplace(-e, i);
            ++freq[p];
        }
    }
    mint ans = 1;
    for (auto [p, q] : pq) {
        if (freq[p] == n) ans *= mint(p).power(-q.top().first);
    }
    while (q--) {
        int i, x;
        cin >> i >> x;
        --i;
        while (x > 1) {
            int p = lp[x], &e = f[i][p];
            auto& q = pq[p];
            if (e == 0 && ++freq[p] == n) q.emplace(0, i);
            while (x % p == 0) ++e, x /= p;
            q.emplace(-e, i);
            if (freq[p] == n) {
                ans /= mint(p).power(-q.top().first);
                while (-q.top().first != f[q.top().second][p]) q.pop();
                ans *= mint(p).power(-q.top().first);
            }
        }
        cout << ans << endl;
    }
    exit(0);
}