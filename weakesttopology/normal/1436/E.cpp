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

template<typename T>
struct G1
{
    static constexpr T id = 0;
    static T op(const T& x, const T& y) { return x + y; }
    static T inv(const T& x) { return -x; }
};

template<typename G>
class BIT
{
private:
    using T = typename remove_const<decltype(G::id)>::type;
    int b(int p) { return p & (-p); }
    const int n;
    vector<T> ft;
    T query(int p)
    {
        T res = G::id;
        for (int i = p; i >= 1; i -= b(i)) res = G::op(ft[i], res);
        return res;
    }
public:
    BIT(int n) : n(n) { ft.assign(n + 1, G::id); }
    BIT(const vector<T>& a) : BIT(size(a), G::id)
    {
        for (int i = 1; i <= n; ++i) ft[i] = G::op(ft[i - 1], a[i - 1]);
        for (int i = n; i >= 1; --i) ft[i] = G::op(G::inv(ft[i - b(i)]), ft[i]);
    }
    T query(int l, int r) { return G::op(G::inv(query(l)), query(r + 1)); }
    void update(int p, T value)
    {
        for (int i = p + 1; i <= n; i += b(i)) ft[i] = G::op(ft[i], value);
    }
};

ll hilbert(int x, int y, int N)
{
    ll d = 0;
    for (int s = N >> 1; s > 0; s >>= 1)
    {
        int rx = (x & s) > 0, ry = (y & s) > 0;
        d += 1LL * s * s * ((3 * rx) ^ ry);
        if (ry == 0)
        {
            if (rx == 1) x = N - 1 - x, y = N - 1 - y;
            swap(x, y);
        }
    }
    return d;
}

int logceil(int n)
{
    return __builtin_clz(1) - __builtin_clz(n) + !!(n & -n);
}

void mo(const auto& queries, auto& eval, auto& remove, auto& insert, int n)
{
    const int q = size(queries), N = 1 << logceil(n);

    debug(N);

    vector<int> Z(q, 0); iota(all(Z), 0);

    vector<ll> h(q, 0LL);

    for (int z = 0; z < q; ++z)
    {
        auto [l, r] = queries[z];
        h[z] = hilbert(l, r, N);
    }

    sort(all(Z), [&h](int z, int w) { return h[z] < h[w]; });

    int lcur = 0, rcur = 0; insert(0);

    auto update = [&](int l, int r)
    {
        while (l < lcur) insert(--lcur);
        while (rcur < r) insert(++rcur);
        while (lcur < l) remove(lcur++);
        while (r < rcur) remove(rcur--);
    };

    for (auto z : Z)
    {
        auto [l, r] = queries[z];
        update(l, r), eval(z);
    }
}

int main()
{ _
    int n; cin >> n;

    vector pos(n + 1, vector(1, -1));

    vector a(n, 0);

    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x; --x;
        pos[x].push_back(i);
        a[i] = x;
    }

    for (int x = 0; x <= n; ++x) pos[x].push_back(n);

    vector Q(0, pair(0, 0));

    vector mex(0, 0);

    for (int x = 0; x <= n; ++x)
    {
        for (int idx = 1; idx < size(pos[x]); ++idx)
        {
            int l = pos[x][idx - 1] + 1, r = pos[x][idx] - 1;
            if (l <= r) Q.emplace_back(l, r), mex.push_back(x);
        }
    }

    int q = size(Q);

    vector res(q, 0), cnt(n, 0);

    BIT<G1<int>> bit(n);

    auto eval = [&](int z) { res[z] = (mex[z] > 0 ? bit.query(0, mex[z] - 1) : 0); };
    auto insert = [&](int i) { if (cnt[a[i]]++ == 0) bit.update(a[i], 1); };
    auto remove = [&](int i) { if (--cnt[a[i]] == 0) bit.update(a[i], -1); };

    mo(Q, eval, remove, insert, n);

    int ans = n + 2;

    vector good(n + 1, 0);

    for (int z = 0; z < q; ++z)
        if (mex[z] == res[z])
            good[mex[z]] = 1;

    for (int x = 0; x <= n; ++x)
        if (not good[x])
        {
            ans = x + 1;
            break;
        }

    cout << ans << endl;

    exit(0);
}