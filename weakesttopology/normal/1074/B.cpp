#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int query(char ch, int u)
{
    cout << ch << " " << u + 1 << endl;
    int res;
    cin >> res;
    --res;
    return res;
}

void answer(int u)
{
    cout << "C " << u + 1 << endl;
}

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> E(n);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    int k[2];
    vector<int> x[2];
    char ch[2] = { 'A', 'B' };

    for (int t = 0; t < 2; ++t)
    {
        cin >> k[t];
        x[t].resize(k[t]);
        for (auto& u : x[t])
        {
            cin >> u;
            --u;
        }
    }

    int s = query(ch[1], x[1][0]);

    vector<int> h(n, -1);
    auto dfs = [&](auto& self, int u) -> void
    {
        for (auto v : E[u]) if (h[v] == -1)
        {
            h[v] = h[u] + 1;
            self(self, v);
        }
    };
    h[s] = 0;
    dfs(dfs, s);

    int v = x[0][0];
    for (auto u : x[0]) if (h[u] < h[v]) v = u;

    int r = query(ch[0], v);

    answer(count(all(x[1]), r) ? v : -2);
}

int main()
{ _
    int t;
    cin >> t;
    while (t--) solve();
    exit(0);
}