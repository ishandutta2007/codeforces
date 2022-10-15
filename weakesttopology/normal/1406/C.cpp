#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) X.begin(), X.end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

void solve()
{
    int n; cin >> n;
    vector E(n, vector(0, 0));
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v; cin >> u >> v; --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    vector subtree(n, 0);
    function<void(int, int)> find_size = [&](int u, int p)
    {
        subtree[u] = 1;
        for (auto v : E[u])
            if (v != p)
            {
                find_size(v, u);
                subtree[u] += subtree[v];
            }
    };
    find_size(0, 0);

    function<void(int, int)> find_max = [&](int u, int p)
    {
        subtree[u] = n - subtree[u];
        for (auto v : E[u])
            if (v != p)
            {
                subtree[u] = max(subtree[u], subtree[v]);
                find_max(v, u);
            }
    };
    find_max(0, 0);

    vector V(n, 0); iota(all(V), 0);
    sort(all(V), [&subtree](int u, int v){ return subtree[u] < subtree[v]; });

    int c1 = V[0], c2 = V[1];

    if (subtree[c1] < subtree[c2])
    {
        cout << 1 << " " << E[0][0] + 1 << endl;
        cout << 1 << " " << E[0][0] + 1 << endl;
    }
    else
    {
        int v = (E[c2][0] == c1) ? E[c2][1] : E[c2][0];

        cout << c2 + 1 << " " << v + 1 << endl;
        cout << c1 + 1 << " " << v + 1 << endl;
    }
}

int main()
{ _
    int t; cin >> t;
    while (t--) solve();
    exit(0);
}