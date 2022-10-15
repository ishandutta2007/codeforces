#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<ll mod>
struct Mint {
    ll x;
    Mint(ll x = 0) : x((x %= mod) < 0 ? x + mod : x) { }
    Mint& operator+=(Mint rhs) { if ((x += rhs.x) >= mod) x -= mod; return *this; }
    Mint& operator-=(Mint rhs) { return *this += mod - rhs.x; }
    Mint& operator*=(Mint rhs) { return ((x *= rhs.x) %= mod, *this); }
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

mint solve() {
    int n, p;
    cin >> n >> p;

    map<int, int> f;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        f[k] += 1;
    }

    if (p == 1) return n % 2;

    vector<pair<int, ll>> fvec(all(f));
    reverse(all(fvec));

    mint res = 0;
    ll need = 0;
    int klast = INF;
    for (auto [k, v] : fvec) {
        for (int j = 0; j < min(20, klast - k); ++j) {
            need = min<ll>(p * need, LINF / p);
        }
        klast = k;

        ll take = min<ll>(need, v);
        need -= take, v -= take;
        res -= take * mint(p).power(k);
        v %= 2;
        if (v) {
            res = mint(p).power(k);
            need = 1;
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) cout << solve() << endl;

    exit(0);
}