#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<typename T>
struct M1 {
    using Type = pair<T, T>;
    inline const static Type Id = pair(numeric_limits<T>::max(), T());
    static Type op(const Type& x, const Type& y) { return min(x, y); }
};

template<typename Monoid>
struct SegmentTree {
private:
    using M = Monoid;
    using T = typename Monoid::Type;
    const int n;
    vector<T> st;
public:
    SegmentTree(int n) : n(n), st(2 * n, M::Id) { }
    SegmentTree(const vector<T>& a) : SegmentTree(size(a)) {
        for (int i = 0; i < n; ++i) st[n + i] = a[i];
        for (int i = n - 1; i > 0; --i)
            st[i] = M::op(st[i << 1], st[i << 1 | 1]);
    }
    void modify(int p, T value) {
        for (st[p += n] = value; p > 1; p >>= 1)
            st[p >> 1] = M::op(st[p & ~1], st[p | 1]);
    }
    T query(int l, int r) {
        T resl = M::Id, resr = M::Id;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resl = M::op(resl, st[l++]);
            if (r & 1) resr = M::op(st[--r], resr);
        }
        return M::op(resl, resr);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    using pii = pair<int, int>;
    vector<pii> from(n), to(n);
    vector<int> xvalues;

    for (int i = 0; i < n; ++i) {
        pii &p = from[i], &q = to[i];
        cin >> p.first >> p.second >> q.first >> q.second;
        xvalues.insert(end(xvalues), {p.first, q.first});
    }

    sort(all(xvalues)), xvalues.erase(unique(all(xvalues)), end(xvalues));
    auto get = [&](int x) {
        return (int)distance(begin(xvalues), lower_bound(all(xvalues), x));
    };
    int m = (int)size(xvalues);

    for (int i = 0; i < n; ++i) {
        to[i].first = get(to[i].first);
        from[i].first = get(from[i].first);
    }

    vector<int> p(n, -1);
    queue<int> q;

    vector<priority_queue<pii, vector<pii>, greater<pii>>> pq(m);

    for (int i = 0; i < n; ++i) {
        if (from[i] == pair(0, 0)) {
            p[i] = i;
            q.push(i);
        }
        else pq[from[i].first].emplace(from[i].second, i);
    }

    SegmentTree<M1<int>> st(m);
    for (int x = 0; x < m; ++x) {
        if (not empty(pq[x])) st.modify(x, pq[x].top());
    }

    while (not empty(q)) {
        int i = q.front();
        q.pop();

        while (true) {
            auto [y, j] = st.query(0, to[i].first);
            if (y > to[i].second) break;

            int x = from[j].first;
            pq[x].pop();
            st.modify(x, empty(pq[x]) ? M1<int>::Id : pq[x].top());

            if (p[j] == -1) {
                p[j] = i;
                q.push(j);
            }
        }
    }

    if (p[n - 1] == -1) cout << -1 << endl;
    else {
        vector<int> ans(1, n - 1);
        for (int u = n - 1; p[u] != u; u = p[u]) ans.push_back(p[u]);

        reverse(all(ans));
        int k = (int)size(ans);
        cout << k << endl;
        for (int j = 0; j < k; ++j) {
            cout << ans[j] + 1 << "\n "[j + 1 < k];
        }
    }

    exit(0);
}