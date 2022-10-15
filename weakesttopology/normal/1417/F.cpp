#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) (X).begin(), (X).end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main()
{ _
    int n, m, q; cin >> n >> m >> q;

    static vector p(n, 0);
    for (auto& x : p) cin >> x;

    vector e(m, pair(0, 0));
    for (auto& [u, v] : e)
    {
        cin >> u >> v; --u, --v;
    }

    vector skip(m, 0);
    vector Q(q, pair(0, 0));
    for (auto& [t, x] : Q)
    {
        cin >> t >> x; --x;
        if (t == 2) skip[x] = 1;
    }

    struct Data
    {
        int v;
        bool operator<(const Data& rhs) const
        {
            return pair(p[v], v) > pair(p[rhs.v], rhs.v);
        }
    };

    auto update = [&](set<Data>& S)
    {
        set<Data> R(S.begin(), S.end());
        swap(S, R);
    };

    vector parent(n, 0); iota(all(parent), 0);
    vector S(n, set<Data>());
    for (int u = 0; u < n; ++u)
        S[u].insert(Data{u});

    auto unite = [&](int u, int v)
    {
        while (u != parent[u]) u = parent[u];
        while (v != parent[v]) v = parent[v];
        if (u != v)
        {
            if (sz(S[u]) < sz(S[v])) swap(u, v);
            parent[v] = u;
            for (auto x : S[v]) S[u].insert(x);
            return v;
        }
        return -1;
    };

    for (int j = 0; j < m; ++j)
    {
        if (skip[j]) continue;
        unite(e[j].first, e[j].second);
    }

    vector child(m, -1);
    for (int z = q - 1; z >= 0; --z)
    {
        auto [t, j] = Q[z];
        if (t == 2) child[j] = unite(e[j].first, e[j].second);
    }

    auto split = [&](int j)
    {
        int v = child[j], u = parent[v];
        assert(u == parent[u]);
        for (auto x : S[v]) S[u].erase(x);
        update(S[v]);
        parent[v] = v;
    };

    for (auto [t, x] : Q)
    {
        if (t == 1)
        {
            while(x != parent[x]) x = parent[x];
            int v = S[x].begin()->v;
            cout << p[v] << endl;
            S[x].erase(S[x].begin());
            p[v] = 0;
            S[x].insert(Data{v});
        }
        else if (child[x] != -1) split(x);
    }

    exit(0);
}