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
    Mint(ll x = 0) : x((x %= mod) < 0 ? x + mod : x) { }
    Mint& operator+=(Mint rhs) { if ((x += rhs.x) >= mod) x -= mod; return *this; }
    Mint& operator-=(Mint rhs) { return *this += mod - rhs.x; }
    Mint& operator*=(Mint rhs) { (x *= rhs.x) %= mod; return *this; }
    Mint& operator/=(Mint rhs) { return *this *= modpow(rhs.x, mod - 2, mod); }
    Mint power(ll p) const { return Mint(modpow(x, p, mod)); }
    bool operator==(Mint rhs) const { return x == rhs.x; }
    bool operator<(Mint rhs) const { return x < rhs.x; }
    friend Mint operator+(Mint lhs, Mint rhs) { return lhs += rhs; }
    friend Mint operator-(Mint lhs, Mint rhs) { return lhs -= rhs; }
    friend Mint operator*(Mint lhs, Mint rhs) { return lhs *= rhs; }
    friend Mint operator/(Mint lhs, Mint rhs) { return lhs /= rhs; }
    friend ostream& operator<<(ostream& out, Mint a) { return out << a.x; }
    friend istream& operator>>(istream& in, Mint& a)
    {
        ll x;
        in >> x;
        a = Mint(x);
        return in;
    }
};

template<typename T>
struct G1
{
    using Type = T;
    inline const static T Id = 0;
    static T op(const T& x, const T& y) { return x + y; }
    static T inv(const T& x) { return Id - x; }
    static bool cmp(const T& x, const T& y) { return x < y; }
};

template<typename Group>
class BIT
{
private:
    using G = Group;
    using T = typename G::Type;
    int b(int p) { return p & (-p); }
    const int n;
    vector<T> ft;
    void update(int p, T value)
    {
        for (int i = p; i >= 1; i -= b(i)) ft[i] = G::op(ft[i], value);
    }
public:
    BIT(int n) : n(n), ft(n + 1, G::Id) { }
    T query(int p)
    {
        T res = G::Id;
        for (int i = p + 1; i <= n; i += b(i)) res = G::op(res, ft[i]);
        return res;
    }
    void update(int l, int r, T value)
    {
        update(r + 1, value), update(l, G::inv(value));
    }
};

int main()
{ _
    constexpr ll mod = 998244353;
    using mint = Mint<mod>;

    int n, q;
    cin >> n >> q;

    vector<vector<int>> E(n);
    vector<int> deg(n, 0);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        E[u].push_back(v), E[v].push_back(u);
        deg[u] += 1, deg[v] += 1;
    }

    const int magic = 500;
    vector<int> heavy;

    for (int u = 0; u < n; ++u)
    {
        if (deg[u] > magic) heavy.push_back(u);
    }

    int ct = 0;
    vector<int> L(n, -1), R(n), p(n);
    auto tour = [&](auto& self, int u, int par) -> void
    {
        L[u] = ct++, p[u] = par;
        for (auto v : E[u]) if (v != par) self(self, v, u);
        R[u] = ct - 1;
    };
    tour(tour, 0, 0);

    constexpr int K = 17;
    vector<array<int, K + 1>> up(n);

    for (int u = 0; u < n; ++u) up[u][0] = p[u];
    for (int x = 1; x <= K; ++x)
    {
        for (int u = 0; u < n; ++u)
            up[u][x] = up[up[u][x - 1]][x - 1];
    }

    auto is_ancestor = [&](int u, int v)
    {
        return L[u] < L[v] && R[v] <= R[u];
    };

    BIT<G1<mint>> bit(n);
    vector<mint> tot(n, 0);

    for (int z = 0; z < q; ++z)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int u;
            cin >> u;
            --u;
            mint d;
            cin >> d;

            tot[u] += d;

            if (deg[u] <= magic)
            {
                for (auto v : E[u]) if (L[u] < L[v])
                {
                    bit.update(L[v], R[v], (n - (R[v] - L[v] + 1)) * d);
                }
                if (p[u] != u)
                {
                    int add = R[u] - L[u] + 1;
                    bit.update(0, n - 1, +add * d);
                    bit.update(L[u], R[u], -add * d);
                }
            }
        }
        else
        {
            int u;
            cin >> u;
            --u;

            mint res = bit.query(L[u]) + n * tot[u];

            for (auto v : heavy)
            {
                if (is_ancestor(v, u))
                {
                    int w = u;
                    for (int k = K; k >= 0; --k)
                    {
                        if (is_ancestor(v, up[w][k])) w = up[w][k];
                    }
                    res += (n - (R[w] - L[w] + 1)) * tot[v];
                }
                else if (v != u)
                {
                    res += (R[v] - L[v] + 1) * tot[v];
                }
            }
            res /= n;

            cout << res << endl;
        }
    }

    exit(0);
}