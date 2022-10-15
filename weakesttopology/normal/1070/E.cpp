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
struct M1
{
    static constexpr T id = 0;
    static T op(const T& x, const T& y) { return x + y; }
    static bool cmp(const T& x, const T& y) { return x < y; }
};

template<typename M>
struct SegmentTree
{
private:
    using T = typename remove_const<decltype(M::id)>::type;
    const int n;
    vector<T> st;
    int binary_search(int p, T prefix, T value)
    {
        while (p < n) if (T x = M::op(prefix, st[p <<= 1]); M::cmp(x, value))
            prefix = x, p |= 1;
        return p - n + M::cmp(M::op(prefix, st[p]), value);
    }
public:
    SegmentTree(int n) : n(n), st(2 * n, M::id) { }
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
        T resl = M::id, resr = M::id;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) resl = M::op(resl, st[l++]);
            if (r & 1) resr = M::op(st[--r], resr);
        }
        return M::op(resl, resr);
    }
    int lower_bound(T value) { return lower_bound(0, n - 1, value); }
    // first x in [a, b] with M::cmp(query(a, x), value) == false
    int lower_bound(int a, int b, T value)
    {
        static deque<int> deq;
        static stack<int> stk;
        for (int l = a + n, r = b + n + 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) deq.push_back(l++);
            if (r & 1) stk.push(--r);
        }
        while (not empty(stk)) deq.push_back(stk.top()), stk.pop();
        for (T prefix = M::id; not empty(deq);)
        {
            int p = deq.front(); deq.pop_front();
            if (T x = M::op(prefix, st[p]); M::cmp(x, value)) prefix = x;
            else { deq.clear(); return binary_search(p, prefix, value); }
        }
        return b + 1;
    }
};

void solve()
{
    int n, m; cin >> n >> m;

    ll t; cin >> t;

    vector p(n, pair(0, 0));

    for (int i = 0; i < n; ++i)
    {
        cin >> p[i].first;
        p[i].second = i;
    }

    sort(all(p));

    SegmentTree<M1<ll>> stcost(n);
    SegmentTree<M1<int>> stcount(n);

    auto compute = [&]()
    {
        int b = stcost.lower_bound(t / 2 + 1) - 1;

        int ct = b >= 0 ? stcount.query(0, b) : 0; ct -= ct % m;

        int i = stcount.lower_bound(ct + 1) - 1;

        if (i == n - 1) return ct;

        ll prefix = i >= 0 ? 2 * stcost.query(0, i) : 0LL;

        int j = stcost.lower_bound(i + 1, n - 1, t - prefix + 1) - 1;

        j = stcount.lower_bound(i + 1, j, m + 1) - 1;

        if (j > i) ct += stcount.query(i + 1, j);

        return ct;
    };

    int ans = 0, opt = 1;

    for (int idx = 0; idx < n;)
    {
        int d = p[idx].first;

        while (idx < n && p[idx].first == d)
        {
            auto [x, z] = p[idx++];
            stcost.modify(z, x + stcost.query(z, z));
            stcount.modify(z, 1 + stcount.query(z, z));
        }

        int cur = compute();

        if (cur > ans) ans = cur, opt = d;
    }

    cout << ans << " " << opt << endl;
}

int main()
{ _
    int t; cin >> t;
    while (t--) solve();
    exit(0);
}