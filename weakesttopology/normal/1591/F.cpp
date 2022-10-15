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
struct F1
{
    using Type = pair<T, T>;
    inline const static Type Tid = Type(0, 0);
    inline const static F1 Fid = F1(1, 0);
    T a, b;
    F1(T a, T b) : a(a), b(b) { }
    void apply(Type& sum, int L, int R) const
    {
        (void)L, (void)R;
        sum.first = a * sum.first + b * sum.second;
    }
    void compose(const F1& op, int L, int R)
    {
        (void)L, (void)R;
        a = op.a * a;
        b = op.a * b + op.b;
    }
    bool operator==(const F1& op) const { return a == op.a && b == op.b; }
    static Type op(Type lhs, const Type& rhs)
    {
        lhs.first += rhs.first, lhs.second += rhs.second;
        return lhs;
    }
};

template<typename F>
class LazyST
{
private:
    using T = typename F::Type;

    const int n;

    vector<T> st;
    vector<F> lazy;

    int left(int p) const { return 2 * p + 1; }
    int right(int p) const { return 2 * p + 2; }

    void push(int p, int l, int r)
    {
        lazy[p].apply(st[p], l, r);
        if (l != r)
        {
            int m = l + (r - l) / 2;
            lazy[left(p)].compose(lazy[p], l, m);
            lazy[right(p)].compose(lazy[p], m + 1, r);
        }
        lazy[p] = F::Fid;
    }
    void update(int p, int l, int r, int ql, int qr, F op)
    {
        if (r < ql || qr < l) push(p, l, r);
        else if (ql <= l && r <= qr)
        {
            lazy[p].compose(op, l, r);
            push(p, l, r);
        }
        else
        {
            int m = l + (r - l) / 2;
            push(p, l, r);
            update(left(p), l, m, ql, qr, op);
            update(right(p), m + 1, r, ql, qr, op);
            st[p] = F::op(st[left(p)], st[right(p)]);
        }
    }
    T query(int p, int l, int r, int ql, int qr)
    {
        if (r < ql || qr < l) return F::Tid;
        push(p, l, r);
        if (ql <= l && r <= qr) return st[p];
        int m = l + (r - l) / 2;
        T resl = query(left(p), l, m, ql, qr);
        T resr = query(right(p), m + 1, r, ql, qr);
        return F::op(resl, resr);
    }
    void build(int p, int l, int r, const vector<T>& a)
    {
        if (l == r) st[p] = a[l];
        else
        {
            int m = l + (r - l) / 2;
            build(left(p), l, m, a), build(right(p), m + 1, r, a);
            st[p] = F::op(st[left(p)], st[right(p)]);
        }
    }
    void partition(auto& q, int p, int l, int r, int ql, int qr)
    {
        if (r < ql || qr < l) return;
        push(p, l, r);
        if (ql <= l && r <= qr) { q.emplace_back(p, l, r); return; }
        int m = l + (r - l) / 2;
        partition(q, left(p), l, m, ql, qr);
        partition(q, right(p), m + 1, r, ql, qr);
    }
    int binary_search(int p, int l, int r, T prefix, T value)
    {
        push(p, l, r);
        if (l == r) { return l + F::cmp(F::op(prefix, st[p]), value); }
        int m = l + (r - l) / 2;
        push(left(p), l, m);
        if (T x = F::op(prefix, st[left(p)]); F::cmp(x, value))
            return binary_search(right(p), m + 1, r, x, value);
        else
            return binary_search(left(p), l, m, prefix, value);
    }
public:
    LazyST(int n) : n(n), st(4 * n + 1, F::Tid), lazy(4 * n + 1, F::Fid) { }
    LazyST(const vector<T>& a) : LazyST(size(a))
    {
        build(0, 0, n - 1, a);
    }
    void update(int l, int r, F op)
    {
        update(0, 0, n - 1, l, r, op);
    }
    T query(int l, int r)
    {
        return query(0, 0, n - 1, l, r);
    }
    int lower_bound(T value)
    {
        return binary_search(0, 0, n - 1, F::Tid, value);
    }
    int lower_bound(int l, int r, T value)
    {
        static vector<tuple<int, int, int>> q;
        partition(q, 0, 0, n - 1, l, r);
        int res = r + 1;
        for (auto [idx, prefix] = pair(0, F::Tid); idx < size(q); ++idx)
        {
            auto [p, l, r] = q[idx];
            if (T x = F::op(prefix, st[p]); F::cmp(x, value)) prefix = x;
            else
            {
                res = binary_search(p, l, r, prefix, value);
                break;
            }
        }
        q.clear();
        return res;
    }
};

int main()
{ _
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    auto values = a;
    values.push_back(0);
    sort(all(values)), values.erase(unique(all(values)), end(values));

    constexpr ll mod = 998244353;
    using mint = Mint<mod>;

    int m = size(values) - 1;
    vector<pair<mint, mint>> init(m);

    for (int j = 0; j < m; ++j)
    {
        init[j].second = values[j + 1] - values[j];
        if (values[j + 1] <= a[0]) init[j].first = init[j].second;
    }

    using F = F1<mint>;
    LazyST<F> st(init);

    for (int i = 1; i < n; ++i)
    {
        mint tot = st.query(0, m - 1).first;
        int idx = (int)distance(begin(values), lower_bound(all(values), a[i]));
        st.update(0, m - 1, F(-1, tot));
        if (idx < m) st.update(idx, m - 1, F(0, 0));
    }

    mint res = st.query(0, m - 1).first;

    cout << res << endl;

    exit(0);
}