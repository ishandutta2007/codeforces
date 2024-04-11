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

template<int mod>
struct Mint
{
    int x;
    Mint(ll x = 0) : x(int((x %= mod) < 0 ? x + mod : x)) {};
    // Mint inv() const { assert(x != 0); return power(*this, mod - 2); }
    Mint& operator+=(const Mint& rhs) { if ((x += rhs.x) >= mod) x -= mod; return *this; }
    Mint& operator-=(const Mint& rhs) { return *this += mod - rhs.x; }
    Mint& operator*=(const Mint& rhs) { x = int((1LL * x * rhs.x) % mod); return *this; }
    // Mint& operator/=(const Mint& rhs) { return *this *= rhs.inv(); }
    Mint operator+(const Mint& rhs) const { return Mint(*this) += rhs; }
    Mint operator-(const Mint& rhs) const { return Mint(*this) -= rhs; }
    Mint operator*(const Mint& rhs) const { return Mint(*this) *= rhs; }
    // Mint operator/(const Mint& rhs) const { return Mint(*this) /= rhs; }
    bool operator==(const Mint& rhs) const { return x == rhs.x; }
    bool operator<(const Mint& rhs) const { return x < rhs.x; }
    operator ll() const { return ll(x); }
    friend ostream& operator<<(ostream& out, const Mint& a) { out << a.x; return out; }
    friend istream& operator>>(istream& in, Mint& a)
    {
        ll x; in >> x;
        a = Mint(x);
        return in;
    }
};

template<typename T>
struct F1
{
    inline const static T Tid = T(0LL, 0, 0);
    inline const static F1 Fid = F1(LINF);
    ll value;
    explicit F1(ll value) : value(value) {}
    void apply(T& old, int L, int R) const
    {
        (void)L, (void)R;
        if (not (*this == Fid))
        {
            auto& [maximum, sum, weight] = old;
            maximum = value, sum = weight * decltype(weight)(value);
        }
    }
    void compose(const F1& op, int L, int R)
    {
        (void)L, (void)R;
        if (not (op == Fid)) value = op.value;
    }
    bool operator==(const F1& op) const { return value == op.value; }
    static T op(const T& x, const T& y)
    {
        return T(max(get<0>(x), get<0>(y)), get<1>(x) + get<1>(y), get<2>(x) + get<2>(y));
    }
    static bool cmp(const T& x, const T& y)
    {
        return get<0>(x) < get<0>(y);
    }
};

template<typename T, template<typename> typename Pack>
class LazyST
{
private:
    using F = Pack<T>;
    const int n;
    vector<T> st;
    vector<F> lazy;

    int left(int p) const { return 2 * p + 1; }
    int right(int p) const { return 2 * p + 2; }

    void push(int p, int l, int r)
    {
        if (lazy[p] == F::Fid) return; // may wanna remove this...

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
    const int mod = 1e9 + 7;
    using M = Mint<mod>;

    int n, k; cin >> n >> k;

    ll L; cin >> L;

    vector<M> xvalues, yvalues;

    vector x(n, 0), y(n, 0), c(n, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i] >> c[i]; --c[i];

        x[i] += 1, y[i] += 1;

        xvalues.emplace_back(x[i]);
        yvalues.emplace_back(y[i]);
    }

    xvalues.insert(end(xvalues), { M(0), M(L + 1) });
    yvalues.insert(end(yvalues), { M(L + 1) });

    sort(all(xvalues)), xvalues.erase(unique(all(xvalues)), end(xvalues));
    sort(all(yvalues)), yvalues.erase(unique(all(yvalues)), end(yvalues));

    x.push_back(size(xvalues) - 1);
    y.push_back(size(yvalues) - 1);

    vector ybucket(size(yvalues), vector(0, 0));

    for (int i = 0; i < n; ++i)
    {
        x[i] = (int)distance(begin(xvalues), lower_bound(all(xvalues), M(x[i])));
        y[i] = (int)distance(begin(yvalues), lower_bound(all(yvalues), M(y[i])));

        ybucket[y[i]].push_back(i);
    }

    M ans = 0LL;

    vector prv(n, -1), nxt(n, size(xvalues) - 1);

    vector<multiset<int>> S(k);

    vector data(size(xvalues), tuple(0LL, M(0), M(0)));

    for (int xl = 1; xl < size(xvalues); ++xl)
    {
        auto& [maximum, sum, weight] = data[xl];
        weight = M(xvalues[xl] - xvalues[xl - 1]);
    }

    using DataType = tuple<ll, M, M>;
    LazyST<DataType, F1> st(data);

    auto update = [&](int l, int r, M value)
    {
        if (r < l) return;

        int m = st.lower_bound(l, r, tuple((ll)value + 1, M(0), M(0)));

        if (m > l) st.update(l, m - 1, F1<DataType>((ll)(value)));
    };

    for (int yu = 0; yu + 1 < size(yvalues); ++yu)
    {
        fill(all(prv), -1), fill(all(nxt), size(xvalues) - 1);

        for (int j = 0; j < k; ++j) S[j].clear();

        st.update(0, size(xvalues) - 1, F1<DataType>(0LL));

        for (int i = 0; i < n; ++i) if (y[i] <= yu)
            S[c[i]].insert(x[i]);

        for (int j = 0; j < k; ++j)
        {
            int last = -1;
            for (auto idx : S[j])
            {
                update(last + 1, idx, xvalues[idx]);
                last = idx;
            }
            update(last + 1, size(xvalues) - 1, L + 1);
        }

        M ydprv = 0, yudelta = yvalues[yu + 1] - yvalues[yu];

        M tot = M(L + 1) * (xvalues[size(xvalues) - 2] - xvalues[0]);

        // debug(yvalues[yu]);

        for (int yd = 0; yd <= yu; ++yd) if (not empty(ybucket[yd]))
        {
            M heights = yudelta * (yvalues[yd] - ydprv);

            M adding = heights * (tot - get<1>(st.query(1, size(xvalues) - 2)));

            // debug(yvalues[yd]);
            // debug(adding);

            ans += adding, ydprv = yvalues[yd];

            for (auto i : ybucket[yd]) S[c[i]].erase(S[c[i]].find(x[i]));

            for (auto i : ybucket[yd])
            {
                auto iter = S[c[i]].lower_bound(x[i]);

                if (iter != end(S[c[i]]))
                    nxt[i] = *iter;
                else
                    nxt[i] = size(xvalues) - 1;

                if (iter != end(S[c[i]]) && *iter == x[i])
                    prv[i] = *iter;
                else if (iter != begin(S[c[i]]))
                    prv[i] = *prev(iter);
                else
                    prv[i] = -1;
            }

            for (auto i : ybucket[yd])
                update(prv[i] + 1, x[i], xvalues[nxt[i]]);
        }
    }

    cout << ans << endl;

    exit(0);
}