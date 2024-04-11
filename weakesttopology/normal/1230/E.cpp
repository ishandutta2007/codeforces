#include "bits/stdc++.h"
#include <algorithm>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef unsigned long long ull;

const int INF = 0x3f3f3f3f;

void dfs(int root, int parent, const vector<vector<int>>& E, const vector<ull>& x, vector<map<ull, int>>& gcd_maps)
{
    gcd_maps[root][x[root]] = 1;
    if (parent)
    {
        for (auto [k, f] : gcd_maps[parent])
            gcd_maps[root][__gcd(k, x[root])] += f;
    }
    for (auto v : E[root])
    {
        if (gcd_maps[v].empty())
            dfs(v, root, E, x, gcd_maps);
    }
}

int main()
{ _
    int n; cin >> n;
    vector<ull> x(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> x[i];

    vector<vector<int>> E(n + 1);
    for (int i = 1; i < n; ++i)
    {
        int u, v; cin >> u >> v;
        E[u].pb(v);
        E[v].pb(u);
    }

    vector<map<ull, int>> gcd_maps(n + 1);

    dfs(1, 0, E, x, gcd_maps);

    ull sum = 0;
    ull mod = 1000000000 + 7;
    for (auto H : gcd_maps)
        for (auto [k, f] : H)
            sum = (sum + k * f) % mod;

    cout << sum << endl;

    exit(0);
}