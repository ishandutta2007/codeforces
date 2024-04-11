#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<typename T>
T power(T x, ll p)
{
    T res = T(1);
    while (p)
    {
        if (p & 1) res *= x;
        p >>= 1, x *= x;
    }
    return res;
}

template<int MOD>
struct Mint
{
    int x;
    Mint(ll x = 0) : x(int((x %= MOD) < 0 ? x + MOD : x)) {};
    Mint inv() const { assert(x != 0); return power(*this, MOD - 2); }
    Mint& operator+=(const Mint& rhs) { if ((x += rhs.x) >= MOD) x -= MOD; return *this; }
    Mint& operator-=(const Mint& rhs) { return *this += MOD - rhs.x; }
    Mint& operator*=(const Mint& rhs) { x = int((1LL * x * rhs.x) % MOD); return *this; }
    Mint& operator/=(const Mint& rhs) { return *this *= rhs.inv(); }
    Mint operator+(const Mint& rhs) const { return Mint(*this) += rhs; }
    Mint operator-(const Mint& rhs) const { return Mint(*this) -= rhs; }
    Mint operator*(const Mint& rhs) const { return Mint(*this) *= rhs; }
    Mint operator/(const Mint& rhs) const { return Mint(*this) /= rhs; }
    bool operator==(const Mint& rhs) const { return x == rhs.x; }
    bool operator<(const Mint& rhs) const { return x < rhs.x; }
    friend ostream& operator<<(ostream& out, const Mint& a) { out << a.x; return out; }
    friend istream& operator>>(istream& in, Mint& a)
    {
        ll x; in >> x;
        a = Mint(x);
        return in;
    }
};

struct StaticSet
{
private:
    const int n;
    vector<int> vis;
    int cnt = 0;
public:
    StaticSet(int n) : n(n), vis(n, 0) { }
    void insert(int x) { if (vis[x]++ == 0) cnt += 1; }
    void erase(int x) { if (--vis[x] == 0) cnt -= 1; }
    int sz() const { return cnt; }
};

int main()
{ _
    constexpr int MOD = 998244353;
    using M = Mint<MOD>;

    int n, m; cin >> n >> m;

    vector l(n, 0), r(n, 0);

    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];

    vector edges(m, pair(0, 0));

    for (auto& [a, b] : edges) { cin >> a >> b; --a, --b; }

    vector f(n + 1, M(1));

    for (int x = 1; x <= n; ++x) f[x] = M(x) * f[x - 1];

    auto C = [&f](int n, int k) { return k <= n && min(k, n) >= 0 ? f[n] / (f[k] * f[n - k]) : M(0); };

    vector cnt(n + 2, 0);

    for (int i = 0; i < n; ++i)
        cnt[l[i]] += 1, cnt[r[i] + 1] -= 1;

    for (int x = 1; x <= n + 1; ++x)
        cnt[x] += cnt[x - 1];

    constexpr int K = 50;

    vector subsetcnt(n + 1, array<M, K>());

    for (int x = 1; x <= n; ++x)
        for (int s = 0; s < K; ++s)
            subsetcnt[x][s] = C(cnt[x] - s, x - s);

    for (int x = 1; x <= n; ++x)
        for (int s = 0; s < K; ++s)
            subsetcnt[x][s] += subsetcnt[x - 1][s];

    auto query = [&subsetcnt](int l, int r, int s)
    {
        return l > 0 ? subsetcnt[r][s] - subsetcnt[l - 1][s] : subsetcnt[r][s];
    };

    M ans = query(1, n, 0);

    StaticSet S(n);

    for (int mask = 1; mask < (1 << m); ++mask)
    {
        int small = 0, big = n + 1;
        for (int j = 0; j < m; ++j) if (mask >> j & 1)
        {
            auto [a, b] = edges[j];
            S.insert(a), S.insert(b);
            small = max({l[a], l[b], small});
            big = min({r[a], r[b], big});
        }

        int sgn = (__builtin_popcount(mask) & 1 ? 1 : -1), s = S.sz();

        if (small <= big && s <= big) ans -= M(sgn) * query(small, big, s);

        for (int j = 0; j < m; ++j) if (mask >> j & 1)
        {
            auto [a, b] = edges[j];
            S.erase(a), S.erase(b);
        }
    }

    cout << ans << endl;

    exit(0);
}