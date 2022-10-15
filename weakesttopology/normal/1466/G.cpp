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
    friend Mint operator+(ll lhs, const Mint& rhs) { return Mint(lhs) + rhs; }
    friend Mint operator-(ll lhs, const Mint& rhs) { return Mint(lhs) - rhs; }
    friend Mint operator*(ll lhs, const Mint& rhs) { return Mint(lhs) * rhs; }
    friend Mint operator/(ll lhs, const Mint& rhs) { return Mint(lhs) / rhs; }
    friend ostream& operator<<(ostream& out, const Mint& a) { return out << a.x; }
    friend istream& operator>>(istream& in, Mint& a)
    {
        ll x; in >> x;
        a = Mint(x);
        return in;
    }
};

vector<int> prefix_function(const string& s)
{
    int n = size(s);
    vector p(n, 0);
    for (int i = 1; i < n; ++i)
    {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]) j = p[j - 1];
        if (s[i] == s[j]) ++j;
        p[i] = j;
    }
    return p;
}

int main()
{ _
    constexpr int mod = 1e9 + 7, K = 26;
    using mint = Mint<mod>;

    int n, q; cin >> n >> q;
    string s, t; cin >> s >> t;

    vector<array<mint, K>> prefix_sum(n);

    mint p = 1 / mint(2), pow = p;

    prefix_sum[0][t[0] - 'a'] = p;

    for (int i = 1; i < n; ++i)
    {
        prefix_sum[i][t[i] - 'a'] = (pow *= p);
        for (int x = 0; x < K; ++x)
            prefix_sum[i][x] += prefix_sum[i - 1][x];
    }

    auto query = [&](int ch, int l, int r)
    {
        return prefix_sum[r][ch] - (l ? prefix_sum[l - 1][ch] : 0);
    };

    const int maxlen = 1e6;
    vector<string> song(1, s);

    while (size(song.back()) < maxlen && size(song) <= n)
    {
        int k = size(song) - 1;
        song.push_back(song.back() + t[k] + song.back());
    }

    for (int z = 0; z < q; ++z)
    {
        int k; cin >> k;
        string w; cin >> w;
        int m = size(w);

        int j = 0;
        while (j < k && size(song[j]) < size(w)) j++;

        const string& r = song[j];

        if (size(r) < size(w))
        {
            cout << 0 << endl;
            continue;
        }

        vector<int> pi_prefix = prefix_function(w + '#' + r);
        vector<int> pi_suffix = prefix_function(r + '#' + w);

        vector<bool> vis_prefix(m + 1, false), vis_suffix(m + 1, false);

        {
            int st = pi_prefix.back();
            while (st > 0)
            {
                vis_prefix[st] = true;
                st = pi_prefix[st - 1];
            }
            vis_prefix[st] = true;
        }
        {
            int st = pi_suffix.back();
            while (st > 0)
            {
                vis_suffix[st] = true;
                st = pi_suffix[st - 1];
            }
            vis_suffix[st] = true;
        }

        int base_count = 0;
        for (auto x : pi_prefix) base_count += (x == m);

        mint ans = base_count * mint(2).power(k - j);
        mint coef = mint(2).power(k);

        if (j < k) for (int i = 0; i < m; ++i)
        {
            if (not (vis_prefix[i] && vis_suffix[m - 1 - i])) continue;
            ans += coef * query(w[i] - 'a', j, k - 1);
        }

        cout << ans << endl;
    }

    exit(0);
}