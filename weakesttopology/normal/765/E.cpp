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
    int n;
    cin >> n;

    vector<vector<int>> E(n);
    vector<int> deg(n);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u, --v;
        E[u].push_back(v), E[v].push_back(u);
        deg[u] += 1, deg[v] += 1;
    }

    vector<set<int>> tail(n);

    queue<int> q;
    for (int u = 0; u < n; ++u)
    {
        if (deg[u] == 1)
        {
            q.push(u);
            tail[u].insert(0);
        }
    }

    bool good = true;

    while (not empty(q) && good)
    {
        int u = q.front();
        q.pop();
        deg[u] -= 1;

        for (auto v : E[u]) if (deg[v])
        {
            if (size(tail[u]) > 1)
            {
                good = false;
                break;
            }

            for (auto x : tail[u])
            {
                tail[v].insert(x + 1);
            }
            tail[u].clear();

            if (--deg[v] == 1) q.push(v);
        }
    }

    debug(good);

    int res = -1;

    if (good)
    {
        for (int u = 0; u < n; ++u) if (not empty(tail[u]))
        {
            for (auto v : E[u]) if (not empty(tail[v]))
            {
                for (auto x : tail[v]) tail[u].insert(x + 1);
            }

            if (size(tail[u]) > 2) break;

            res = 0;
            for (auto x : tail[u]) res += x;

            while (res % 2 == 0) res = res / 2;

            break;
        }
    }

    cout << res << endl;

    exit(0);
}