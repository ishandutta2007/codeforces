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

void fail(const string& s)
{
    debug(s);
    cout << 0 << endl;
    exit(0);
}

int main()
{ _
    int n, k; cin >> n >> k;

    vector p(n, 0);

    for (auto& x : p) { cin >> x; --x; }

    vector nxt(n, -1), start(n, 1);

    for (int j = 0; j < k; ++j)
    {
        int x, y; cin >> x >> y; --x, --y;
        nxt[x] = y, start[y] = 0;
    }

    vector vis(n, 0), Id(n, -1);

    for (int x = 0, t = 1; x < n; ++x) if (start[x])
    {
        int y = x;
        while (y != -1)
        {
            if (vis[y]) fail("not a path");
            vis[y] = t++, Id[y] = x, y = nxt[y];
        }
    }

    if (*min_element(all(vis)) == 0) fail("not visiting");

    vector E(n, vector(0, 0));
    vector indeg(n, 0);

    for (int x = 0; x < n; ++x) if (p[x] != -1)
    {
        if (Id[p[x]] == Id[x])
        {
            if (vis[p[x]] > vis[x]) fail("inconsistent path");
            else continue;
        }
        E[Id[p[x]]].push_back(Id[x]);
        indeg[Id[x]] += 1;
    }

    queue<int> q;

    for (int x = 0; x < n; ++x) if (start[x] && indeg[Id[x]] == 0)
    {
        // debug(Id[x]);
        q.push(Id[x]);
    }

    vector<int> topo;

    while (not empty(q))
    {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (auto v : E[u]) if (--indeg[v] == 0)
            q.push(v);
    }

    vector<int> ans;

    for (auto u : topo)
    {
        for (int x = u; x != -1; x = nxt[x])
            ans.push_back(x + 1);
    }

    if (size(ans) != n) fail("not all");

    for (int i = 0; i < n; ++i) cout << ans[i] << "\n "[i + 1 < n];

    exit(0);
}