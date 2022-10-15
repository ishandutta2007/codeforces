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
struct F2
{
    using Type = T;
    inline const static T Tid = T(0);
    inline const static F2 Fid = F2(T(LINF));
    T value;
    explicit F2(T value) : value(value) {}
    void apply(T& old, int L, int R) const
    {
        if (*this == Fid) return;
        old = (R - L + 1) * value;
    }
    void compose(const F2& op, int L, int R)
    {
        (void)L, (void)R;
        if (op == Fid) return;
        value = op.value;
    }
    bool operator==(const F2& op) const { return value == op.value; }
    static T op(const T& x, const T& y)
    {
        return x + y;
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

string solve()
{
    int n, q;
    cin >> n >> q;
    string s, f;
    cin >> s >> f;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = f[i] - '0';

    LazyST<F2<int>> st(a);

    vector<pair<int, int>> queries(q);
    for (auto& [l, r] : queries)
    {
        cin >> l >> r;
        --l, --r;
    }
    reverse(all(queries));

    for (auto [l, r] : queries)
    {
        int sum = st.query(l, r);

        int len = r - l + 1;

        if (2 * sum == len) return "NO";

        st.update(l, r, F2<int>(2 * sum < len ? 0 : 1));
    }

    bool good = true;
    for (int i = 0; i < n; ++i)
    {
        if (st.query(i, i) != s[i] - '0')
        {
            good = false;
            break;
        }
    }

    return good ? "YES" : "NO";
}

int main()
{ _
    int t;
    cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}