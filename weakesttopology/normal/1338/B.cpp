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

int solvemax(const auto& E)
{
    int n = size(E);

    int leaves = 0, ans = 0;

    vector vis(n, 0);

    for (int u = 0; u < n; ++u) if (size(E[u]) == 1)
    {
        leaves += 1;
        if (not vis[E[u][0]]++) ans += 1;
    }

    ans += n - 1 - leaves;

    return ans;
}

int solvemin(const auto& E)
{
    int n = size(E);

    vector color(n, -1);

    function<void(int)> paint = [&](int u)
    {
        for (auto v : E[u]) if (color[v] == -1)
        {
            color[v] = color[u] ^ 1;
            paint(v);
        }
    };

    color[0] = 0;
    paint(0);

    vector leafcolors(0, 0);

    for (int u = 0; u < n; ++u) if (size(E[u]) == 1)
        leafcolors.push_back(color[u]);

    sort(all(leafcolors)), leafcolors.erase(unique(all(leafcolors)), end(leafcolors));

    return size(leafcolors) == 1 ? 1 : 3;
}

int main()
{ _
    int n; cin >> n;

    vector E(n, vector(0, 0));

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v; cin >> u >> v; --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    cout << solvemin(E) << " " << solvemax(E) << endl;

    exit(0);
}