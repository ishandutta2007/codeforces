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

int b(int p) { return p & (-p); }

template<typename T>
struct BIT
{
    const int n;
    const T inf = numeric_limits<T>::max();
    vector<T> ft;
    BIT(int n) : n(n), ft(n + 1, inf) { }
    T query(int p)
    {
        T res = inf;
        for (p += 1; p <= n; p += b(p)) res = min(ft[p], res);
        return res;
    }
    void update(int p, T value)
    {
        for (p += 1; p >= 1; p -= b(p)) ft[p] = min(ft[p], value);
    }
};

template<typename T>
struct M1
{
    using Type = T;
    inline const static T Id = -1;
    static T op(const T& x, const T& y) { return max(x, y); }
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

void solve(const vector<int>& a, const vector<int>& values, const vector<pair<int, int>>& queries, vector<int>& res)
{
    const int n = size(a), m = size(values);

    vector<vector<int>> I(n);

    for (int z = 0; z < size(queries); ++z) I[queries[z].second].push_back(z);

    SegmentTree<M1<int>> st(m);
    BIT<int> bit(n);

    stack<int> stk;

    for (int i = 0; i < n; ++i)
    {
        while (not empty(stk) && a[stk.top()] < a[i]) stk.pop();

        auto itercur = lower_bound(all(values), a[i]);
        int idx = (int)distance(begin(values), itercur);

        if (not empty(stk))
        {
            auto getnxt = [&](int j)
            {
                if (a[j] == a[i]) return -1;
                auto iterr = upper_bound(itercur, end(values), (a[i] + a[j]) / 2);
                int jdx = (int)distance(begin(values), iterr);
                return idx == jdx ? -1 : st.query(idx, jdx - 1);
            };
            for (int j = stk.top(); j != -1; j = getnxt(j)) bit.update(j, a[j] - a[i]);
        }

        st.modify(idx, i);
        stk.push(i);

        for (auto z : I[i]) res[z] = min(res[z], bit.query(queries[z].first));
    }
}

int main()
{ _
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    auto values = a;
    sort(all(values)), values.erase(unique(all(values)), end(values));

    int q;
    cin >> q;

    vector<pair<int, int>> queries(q);
    for (auto& [l, r] : queries)
    {
        cin >> l >> r;
        --l, --r;
    }

    vector<int> res(q, INF);

    solve(a, values, queries, res);

    reverse(all(a));

    for (auto& [l, r] : queries)
    {
        l = n - 1 - l, r = n - 1 - r;
        swap(l, r);
    }

    solve(a, values, queries, res);

    for (int z = 0; z < q; ++z) cout << res[z] << endl;

    exit(0);
}