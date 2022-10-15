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

template<typename T, int K = 400>
struct SQRT
{
    const int n, blocks;
 
    vector<T> arr, offset;
    vector<vector<int>> bucket;
 
    void sort_bucket(int b) {
        sort(all(bucket[b]), [&](int i, int j){ return arr[i] < arr[j]; });
    }
 
    SQRT(const vector<T>& arr) : n(size(arr)), blocks((n + K - 1) / K), arr(arr), offset(blocks, 0), bucket(blocks) {
        for (int b = 0; b < blocks; ++b) {
            int len = min(K, n - b * K);
            bucket[b].resize(len), iota(all(bucket[b]), b * K);
            sort_bucket(b);
        }
    }
    // O(n/K + K)
    void update(int l, int r, T add) {
        int s = l / K, e = r / K;

        for (int b = s + 1; b <= e - 1; ++b) offset[b] += add;
        for (int i = l; i <= min(r, s * K + K - 1); ++i) arr[i] += add;

        auto cmp = [&](int i, int j){ return arr[i] < arr[j]; };
        auto pred = [&](int i) { return l <= i && i <= r; };

        auto mids = stable_partition(all(bucket[s]), pred);
        inplace_merge(begin(bucket[s]), mids, end(bucket[s]), cmp);

        if (s != e) {
            for (int i = e * K; i <= r; ++i) arr[i] += add;
            auto mide = stable_partition(all(bucket[e]), pred);
            inplace_merge(begin(bucket[e]), mide, end(bucket[e]), cmp);
        }
    }
    // O((n/K)log(K))
    int order_of_key(T key) {
        int res = 0;
        for (int b = 0; b < blocks; ++b) {
            auto iter = lower_bound(all(bucket[b]), key - offset[b], [&](int i, T x){ return arr[i] < x; });
            res += (int)distance(begin(bucket[b]), iter);
        }
        return res;
    }
};

struct HLD
{
    const int n;
    const vector<vector<int>>& E;

    vector<int> parent, depth, heavy, head, pos;
    int cur_pos = 0;

    HLD(const auto& E, int root = 0) : n(size(E)), E(E),
        parent(n), depth(n), heavy(n, -1), head(n), pos(n)
    {
        parent[root] = root;
        dfs(root), decompose(root, root);
    }

    int dfs(int u)
    {
        int weight = 1, prv_max = 0;

        for (int v : E[u]) if (v != parent[u])
        {
            parent[v] = u, depth[v] = depth[u] + 1;
            int cur = dfs(v);
            weight += cur;
            if (cur > prv_max) prv_max = cur, heavy[u] = v;
        }

        return weight;
    }
    void decompose(int u, int h)
    {
        head[u] = h, pos[u] = cur_pos++;

        if (heavy[u] != -1) decompose(heavy[u], h);
        for (int v : E[u]) if (v != parent[u] && v != heavy[u])
            decompose(v, v);
    }
    void update(int a, int b, auto& st, const auto& upd)
    {
        for (; head[a] != head[b]; a = parent[head[a]])
        {
            if (depth[head[b]] > depth[head[a]]) swap(a, b);
            st.update(pos[head[a]], pos[a], upd);
        }

        if (depth[a] > depth[b]) swap(a, b);
        st.update(pos[a], pos[b], upd);
    }
};

int main()
{ _
    int n, m; cin >> n >> m;

    vector E(n, vector(0, 0));
    vector p(n, -1);

    for (int u = 1; u < n; ++u)
    {
        cin >> p[u]; --p[u];
        E[p[u]].push_back(u);
    }

    HLD hld(E, 0);

    vector t(n, 0);

    for (int u = 0; u < n; ++u)
    {
        cin >> t[hld.pos[u]];
    }

    SQRT<int, 700> sqrtdecomp(t);

    for (int j = 0; j < m; ++j)
    {
        int q; cin >> q;

        int v = abs(q) - 1, sgn = q / abs(q);

        hld.update(0, v, sqrtdecomp, -sgn);

        sqrtdecomp.update(hld.pos[v], hld.pos[v], sgn * INF);

        int ans = sqrtdecomp.order_of_key(0);

        cout << ans << "\n "[j + 1 < m];
    }

    exit(0);
}