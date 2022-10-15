#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

ll modpow(ll x, ll p, ll mod)
{
    x %= mod, (p %= mod - 1) < 0 ? p += mod - 1 : 0LL;
    ll res = 1LL;
    while (p > 0)
    {
        if (p & 1) res = res * x % mod;
        (x *= x) %= mod, p >>= 1;
    }
    return res;
}

template<int mod>
struct Mint
{
    int x;
    Mint(ll x = 0) : x(int((x %= mod) < 0 ? x + mod : x)) {  }
    Mint& operator+=(const Mint& rhs) { if ((x += rhs.x) >= mod) x -= mod; return *this; }
    Mint& operator-=(const Mint& rhs) { return *this += mod - rhs.x; }
    Mint& operator*=(const Mint& rhs) { x = int((1LL * x * rhs.x) % mod); return *this; }
    Mint& operator/=(const Mint& rhs) { return *this *= Mint(modpow(rhs.x, mod - 2, mod)); }
    Mint operator+(const Mint& rhs) const { return Mint(*this) += rhs; }
    Mint operator-(const Mint& rhs) const { return Mint(*this) -= rhs; }
    Mint operator*(const Mint& rhs) const { return Mint(*this) *= rhs; }
    Mint operator/(const Mint& rhs) const { return Mint(*this) /= rhs; }
    Mint power(ll p) const { return Mint(modpow(x, p, mod)); }
    bool operator==(const Mint& rhs) const { return x == rhs.x; }
    bool operator<(const Mint& rhs) const { return x < rhs.x; }
    friend ostream& operator<<(ostream& out, const Mint& a) { return out << a.x; }
    friend istream& operator>>(istream& in, Mint& a)
    {
        ll x; in >> x;
        a = Mint(x);
        return in;
    }
};

int main()
{ _
    constexpr int mod = 1e9 + 7;
    using Mi = Mint<mod>;

    int n; cin >> n;

    vector<int> l(n), r(n);

    for (int i = 0; i < n; ++i) cin >> l[i];
    for (int i = 0; i < n; ++i) cin >> r[i];

    vector<Mi> p(n, 1);

    for (int i = 0; i < n; i++) p[i] /= r[i] - l[i] + 1;

    auto diff_nxt = [&](int i)
    {
        int L = max(l[i], l[i + 1]), R = min(r[i], r[i + 1]);
        Mi res = 1;
        if (L <= R) res = Mi(1) - p[i] * p[i + 1] * (R - L + 1);
        return res;
    };

    auto diff_mid = [&](int i)
    {
        enum State { leave = 0, enter = 1 };
        vector<tuple<int, State, int>> Ev;
        for (auto j : { i - 1, i + 1 })
        {
            int L = max(l[i], l[j]), R = min(r[i], r[j]);
            if (L <= R)
            {
                int mask = 1 << (j - (i - 1));
                Ev.emplace_back(L, enter, mask);
                Ev.emplace_back(R + 1, leave, mask);
            }
        }
        Ev.emplace_back(l[i], enter, 1 << 1);
        Ev.emplace_back(r[i] + 1, leave, 1 << 1);
        sort(all(Ev));

        Mi prob[8]; fill(all(prob), Mi(1));

        prob[0] = 0;

        for (int mask = 0; mask < 8; ++mask) if (mask & (1 << 0)) prob[mask] *= Mi(1) - p[i - 1];
        for (int mask = 0; mask < 8; ++mask) if (mask & (1 << 1)) prob[mask] *= p[i];
        for (int mask = 0; mask < 8; ++mask) if (mask & (1 << 2)) prob[mask] *= Mi(1) - p[i + 1];

        int mask = 0, last = 0;

        Mi res = 0;

        for (auto [x, state, add] : Ev)
        {
            res += prob[mask] * (x - last);
            mask ^= add, last = x;
        }

        return res;
    };

    vector<Mi> nxt(n), mid(n);

    Mi ans = 1, sum_nxt = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        nxt[i] = diff_nxt(i);
        if (i > 0) mid[i] = diff_mid(i);

        ans += nxt[i] * 3, sum_nxt += nxt[i];
    }

    for (int i = 0; i < n - 1; ++i)
    {
        ans += nxt[i] * sum_nxt;
        for (int j = max(0, i - 1); j < min(n - 1, i + 2); ++j)
            ans -= nxt[i] * nxt[j];

        for (int j = max(1, i); j < min(n - 1, i + 2); ++j)
            ans += mid[j];
    }

    cout << ans << endl;

    exit(0);
}