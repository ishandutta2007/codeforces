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
struct Data {
    mint sum = 0, wsum = 0, sq = 0, wsq = 0, cnt = 1, w = 0;
    Data operator+(Data rhs) const {
        Data res;
        res.sq = sq * rhs.cnt + rhs.sq * cnt + 2 * sum * rhs.sum;
        res.wsq =
            wsq * rhs.cnt + rhs.wsq * cnt +
            2 * (wsum * rhs.sum + rhs.wsum * sum) +
            w * rhs.sq + rhs.w * sq;
        res.sum = sum * rhs.cnt + rhs.sum * cnt;
        res.wsum =
            wsum * rhs.cnt + sum * rhs.w +
            rhs.wsum * cnt + rhs.sum * w;
        res.cnt = cnt * rhs.cnt;
        res.w = w * rhs.cnt + rhs.w * cnt;
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    const int amax = 1e5;
    vector<Data> f(amax + 1);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        ll a, p;
        cin >> a >> p;
        Data res, x;
        x.sum = x.wsum = a;
        x.sq = x.wsq = a * a;
        x.w = 1, x.cnt = 2;
        while (p) {
            if (p & 1) res = res + x;
            p >>= 1, x = x + x;
        }
        f[a] = res;
    }
    for (int d = 1; d <= amax; ++d) {
        for (int x = 2 * d; x <= amax; x += d) {
            f[d] = f[d] + f[x];
        }
    }
    vector<mint> wsq(amax), sq(amax);
    for (int d = amax; d >= 1; --d) {
        wsq[d] = f[d].wsq, sq[d] = f[d].sq;
        for (int x = 2 * d; x <= amax; x += d) {
            wsq[d] -= wsq[x];
            sq[d] -=  sq[x];
        }
    }
    mint ans = wsq[1] - sq[1];
    cout << ans << endl;
    exit(0);
}