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

auto tarjan(const auto& E)
{
    int n = size(E);
    vector low(n, -1), num(n, -1), scc(n, -1), active(n, 0);
    stack<int> st; int ct = 0;
    function<void(int)> dfs = [&](int u)
    {
        low[u] = num[u] = ct++;
        active[u] = 1; st.push(u);
        for (auto v : E[u])
        {
            if (num[v] == -1) dfs(v);
            if (active[v]) low[u] = min(low[u], low[v]);
        }
        if (low[u] == num[u]) do
        {
            scc[st.top()] = u;
            active[st.top()] = 0; st.pop();
        } while (not st.empty() && num[st.top()] >= num[u]);
    };
    for (int u = 0; u < n; ++u) if (num[u] == -1) dfs(u);
    return scc;
}

int solve()
{
    int n, m; cin >> n >> m;

    swap(n, m);

    vector<int> x(n), y(n), row(m, -1), col(m, -1);

    for (int u = 0; u < n; ++u)
    {
        cin >> x[u] >> y[u]; --x[u], --y[u];
        row[x[u]] = u, col[y[u]] = u;
    }

    vector<vector<int>> E(n);

    int ans = 0;

    for (int u = 0; u < n; ++u) if (x[u] != y[u])
    {
        if (row[y[u]] != -1) E[u].push_back(row[y[u]]);
        if (col[x[u]] != -1) E[u].push_back(col[x[u]]);

        ans += 1;
    }

    auto scc = tarjan(E);

    vector<int> leaf(n, 0), weight(n, 0);

    for (int u = 0; u < n; ++u) if (not empty(E[u])) leaf[scc[u]] = 1;

    for (int u = 0; u < n; ++u) if (x[u] != y[u])
    {
        weight[scc[u]] += 1;
        if (size(E[u]) <= 1) weight[scc[u]] = -INF;
        for (auto v : E[u]) if (scc[u] != scc[v]) leaf[scc[u]] = 0;
    }

    for (int u = 0; u < n; ++u) if (x[u] != y[u])
    {
        ans += weight[u] > 1 && leaf[u];
    }

    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}