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

struct DSU
{
    vector<int> p, rk;
    DSU(int n) : p(n), rk(n, 0)
    {
        iota(all(p), 0);
    }
    int find(int i) { return (p[i] == i) ? i : p[i] = find(p[i]); }
    bool unite(int i, int j)
    {
        int x = find(i), y = find(j);
        if (rk[x] < rk[y]) swap(x, y);
        if (x != y)
        {
            p[y] = x, rk[x] += (rk[x] == rk[y]);
            return true;
        }
        else return false;
    }
};

ll solve()
{
    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<tuple<ll, int, int>> edges(m);

    for (auto& [w, u, v] : edges)
    {
        cin >> u >> v >> w;
        --u, --v;
    }
    sort(all(edges));

    DSU dsu(n);
    ll res = 0;

    for (auto [w, u, v] : edges)
    {
        if (dsu.unite(u, v)) res += max(0LL, w - k);
    }

    if (res == 0)
    {
        res = LINF;
        for (auto [w, u, v] : edges)
        {
            res = min(res, abs(w - k));
        }
    }

    return res;
}

int main()
{ _
    int t;
    cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}