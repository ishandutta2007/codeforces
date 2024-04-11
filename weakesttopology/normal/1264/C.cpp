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

template<typename T>
struct M1
{
    using Type = T;
    inline const static T Id = T();
    static T op(const T& x, const T& y) { return x + y; }
    static bool cmp(const T& x, const T& y) { return x < y; }
};

template<typename Monoid>
struct SegmentTree
{
private:
    using M = Monoid;
    using T = typename Monoid::Type;
    const int n;
    vector<T> st;
public:
    SegmentTree(int n) : n(n), st(2 * n, M::Id) { }
    SegmentTree(const vector<T>& a) : SegmentTree(size(a))
    {
        for (int i = 0; i < n; ++i) st[n + i] = a[i];
        for (int i = n - 1; i > 0; --i)
            st[i] = M::op(st[i << 1], st[i << 1 | 1]);
    }
    void modify(int p, T value)
    {
        for (st[p += n] = value; p > 1; p >>= 1)
            st[p >> 1] = M::op(st[p & ~1], st[p | 1]);
    }
    T query(int l, int r)
    {
        T resl = M::Id, resr = M::Id;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) resl = M::op(resl, st[l++]);
            if (r & 1) resr = M::op(st[--r], resr);
        }
        return M::op(resl, resr);
    }
};

template<typename T>
struct MirrorDistribution
{
    int len = 0;
    T weighted = 0, unweighted = 0, prod = 1;

    MirrorDistribution operator+(const MirrorDistribution& rhs) const
    {
        const MirrorDistribution& lhs = *this;

        MirrorDistribution res;

        res.len = lhs.len + rhs.len;
        res.weighted = lhs.weighted + T(lhs.len) * lhs.prod * rhs.unweighted + lhs.prod * rhs.weighted;
        res.unweighted = lhs.unweighted + lhs.prod * rhs.unweighted;
        res.prod = lhs.prod * rhs.prod;

        return res;
    }
    T get()
    {
        T expT = weighted + T(len) * prod;
        T expN = T(1) / prod;
        return expT * expN;
    }
};

int main()
{ _
    const int mod = 998244353;
    using Mi = Mint<mod>;

    int n, q; cin >> n >> q;

    vector<Mi> p(n, Mi(1) / 100);

    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        p[i] *= x;
    }

    using MD = MirrorDistribution<Mi>;
    vector<MD> init(n);

    for (int i = 0; i < n; ++i)
    {
        init[i].len = 1;
        init[i].weighted = init[i].unweighted = Mi(1) - p[i];
        init[i].prod = p[i];
    }

    SegmentTree<M1<MD>> stdist(init);

    auto get = [&](int l, int r) { return stdist.query(l, r).get(); };

    set<int> S = { 0, n };
    vector<Mi> cost(n + 1, 0);

    Mi ans = cost[0] = get(0, n - 1);

    for (int z = 0; z < q; ++z)
    {
        int u; cin >> u; --u;

        if (S.count(u))
        {
            auto iter = S.find(u);

            int l = *prev(iter), r = *next(iter);

            ans -= cost[l] + cost[u];
            cost[l] = get(l, r - 1);
            ans += cost[l];

            S.erase(iter);
        }
        else
        {
            auto iter = S.insert(u).first;

            int l = *prev(iter), r = *next(iter);

            ans -= cost[l];
            cost[l] = get(l, u - 1), cost[u] = get(u, r - 1);
            ans += cost[l] + cost[u];
        }

        cout << ans << endl;
    }

    exit(0);
}