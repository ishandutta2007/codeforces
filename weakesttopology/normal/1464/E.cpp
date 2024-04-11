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
    ll res = 1LL;
    for (; p; p >>= 1, (x *= x) %= mod) if (p & 1) (res *= x) %= mod;
    return res;
}

template<ll mod>
struct Mint
{
    ll x;
    Mint(ll x = 0) : x((x %= mod) < 0 ? x + mod : x) {  }
    Mint& operator+=(const Mint& rhs) { if ((x += rhs.x) >= mod) x -= mod; return *this; }
    Mint& operator-=(const Mint& rhs) { return *this += mod - rhs.x; }
    Mint& operator*=(const Mint& rhs) { (x *= rhs.x) %= mod; return *this; }
    Mint& operator/=(const Mint& rhs) { return *this *= modpow(rhs.x, mod - 2, mod); }
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

template<typename T>
vector<T> fwht(vector<T> a, bool inverse)
{
    int len = size(a);
    assert((len & (len - 1)) == 0);

    for (int k = 1; k < len; k *= 2)
    {
        for (int i = 0; i < len; i += 2 * k)
        {
            for (int j = i; j < i + k; ++j)
            {
                T x = a[j], y = a[j + k];
                a[j] = x + y, a[j + k] = x - y;
            }
        }
    }

    if (not inverse)
    {
        T inv = T(1) / len;
        for (int i = 0; i < len; ++i) a[i] *= inv;
    }

    return a;
}

int main()
{ _
    int n, m; cin >> n >> m;

    vector<vector<int>> E(n);
    vector<int> indeg(n, 0);

    for (int j = 0; j < m; ++j)
    {
        int u, v; cin >> u >> v; --u, --v;
        E[u].push_back(v);
        indeg[v] += 1;
    }

    queue<int> q;
    for (int u = 0; u < n; ++u) if (indeg[u] == 0) q.push(u);

    vector<int> topo;

    while (not empty(q))
    {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (auto v : E[u]) if (--indeg[v] == 0) q.push(v);
    }

    reverse(all(topo));

    constexpr int N = 1 << 9, mod = 998244353;
    using mint = Mint<mod>;

    mint inv = mint(1) / (n + 1);

    vector<int> g(n, 0);
    vector<mint> gct(N), constant(N, inv);

    constant[0] = 0;

    for (auto u : topo)
    {
        vector<int> nxt;
        for (auto v : E[u]) nxt.push_back(g[v]);
        sort(all(nxt)), nxt.erase(unique(all(nxt)), end(nxt));
        while (g[u] < size(nxt) && nxt[g[u]] == g[u]) ++g[u];
        gct[g[u]] += 1;
    }

    for (auto& x : gct) x *= inv * N;

    auto gct_hat = fwht(gct, false), constant_hat = fwht(constant, false);

    vector<mint> p_hat(N);

    for (int x = 0; x < N; ++x) p_hat[x] = constant_hat[x] / (1 - gct_hat[x]);

    auto p = fwht(p_hat, true);

    cout << p[0] << endl;

    exit(0);
}