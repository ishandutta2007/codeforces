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

string solve()
{
    int n, a, b, da, db; cin >> n >> a >> b >> da >> db;
    --a, --b;

    vector E(n, vector(0, 0));
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v; cin >> u >> v; --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    int diam = 0;
    vector dist(n, 0);
    function<int(int, int, int)> dfs = [&](int u, int h, int p)
    {
        int x = dist[u] = h;
        for (auto v : E[u]) if (v != p)
        {
            int y = dfs(v, h + 1, u);
            diam = max(diam, x + y - 2 * h);
            x = max(x, y);
        }
        return x;
    };
    dfs(a, 0, -1);

    if (min(diam, db) > 2 * da && dist[b] > da)
        return "Bob";
    else
        return "Alice";
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}