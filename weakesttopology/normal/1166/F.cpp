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

template<typename T, bool memory_optimized = false>
struct DSU
{
private:
    vector<int> p, rk;
    vector<T> aggregate;
    const function<void(T&, T&)> merger;
    int components;
public:
    DSU(int n, T value, auto merger) : DSU(vector<T>(n, value), merger) { }
    DSU(const vector<T>& agg, auto merger) :
        p(size(agg)), rk(size(agg), 0), aggregate(agg), merger(merger), components(size(agg))
    {
        iota(all(p), 0);
    }
    int find(int u) { return p[u] == u ? u : p[u] = find(p[u]); }
    bool is_same_set(int i, int j) { return find(i) == find(j); }
    T& query(int u) { return aggregate[find(u)]; }
    int (size)() const { return components; }
    void unite(int u, int v)
    {
        u = find(u), v = find(v);
        if (rk[u] < rk[v]) swap(u, v);
        if (u != v)
        {
            rk[u] += (rk[u] == rk[v]), p[v] = p[u];
            merger(aggregate[u], aggregate[v]);
            if (memory_optimized) aggregate[v].~T();
        }
    }
};

int main()
{ _
    int n, m, c, q; cin >> n >> m >> c >> q;

    map<pair<int, int>, int> Id;

    int ptr = 0;
    auto get = [&](int c, int u)
    {
        pair<int, int> p(c, u);
        return Id.count(p) ? Id[p] : Id[p] = ptr++;
    };

    const int max_vtx = n + 4 * m + 4 * q;

    auto merger = [&](set<int>& U, set<int>& V)
    {
        if (size(U) < size(V)) swap(U, V);
        U.insert(all(V));
    };
    DSU<set<int>, true> dsu(max_vtx, set<int>(), merger);

    auto add_edge = [&]()
    {
        int u, v, c; cin >> u >> v >> c; --u, --v, --c;

        // even
        dsu.unite(get(-1, u), get(c, v));
        dsu.unite(get(-1, v), get(c, u));

        // odd
        dsu.query(get(-1, u)).insert(v);
        dsu.query(get(-1, v)).insert(u);
    };

    for (int j = 0; j < m; ++j) add_edge();

    for (int z = 0; z < q; ++z)
    {
        char type; cin >> type;

        if (type == '+')
        {
            add_edge();
        }
        else
        {
            int u, v; cin >> u >> v; --u, --v;

            bool even = dsu.is_same_set(get(-1, u), get(-1, v));
            bool odd = dsu.query(get(-1, u)).count(v);

            string ans = even || odd ? "Yes" : "No";

            cout << ans << endl;
        }
    }

    exit(0);
}