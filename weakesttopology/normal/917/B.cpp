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

int main()
{ _
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> E(n);
    vector<int> indeg(n, 0);

    for (int j = 0; j < m; ++j)
    {
        int u, v;
        char c;
        cin >> u >> v >> c;
        --u, --v;

        E[u].emplace_back(v, c - 'a');
        indeg[v] += 1;
    }

    queue<int> q;

    for (int u = 0; u < n; ++u)
    {
        if (indeg[u] == 0) q.push(u);
        sort(all(E[u]));
    }

    vector<int> topo;

    while (not empty(q))
    {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (auto [v, c] : E[u])
        {
            if (--indeg[v] == 0) q.push(v);
        }
    }

    constexpr int K = 26;

    vector<int> memo(n * n * K, -1);

    auto Id = [&](int x, int u, int v)
    {
        return x * n * n + u * n + v;
    };

    auto solve_impl = [&](auto& self, int x, int u, int v)
    {
        int& ref = memo[Id(x, u, v)];

        if (ref != -1) return ref;

        ref = 0;

        for (auto [w, y] : E[u]) if (y >= x)
        {
            if (not self(self, y, v, w))
            {
                ref = 1;
                break;
            }
        }

        //if (ref)
        //{
        //    for (int y = 0; y < x; ++y) memo[Id(x, u, v)] = 1;
        //}
        //else
        //{
        //    for (int y = x + 1; y < K; ++y) memo[Id(y, u, v)] = 0;
        //}

        return ref;
    };
    auto solve = [&](int x, int u, int v) { return solve_impl(solve_impl, x, u, v); };

    for (int u = 0; u < n; ++u)
    {
        for (int v = 0; v < n; ++v)
        {
            char ans = solve(0, u, v) ? 'A' : 'B';
            cout << ans;
        }
        cout << endl;
    }

    exit(0);
}