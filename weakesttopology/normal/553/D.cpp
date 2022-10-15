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

bool chmax(auto& x, auto y) { return x < y ? (x = y, true) : false; }

int main()
{ _
    int n, m, k; cin >> n >> m >> k;

    vector<bool> rem(n, false), fortress(n, false);

    for (int j = 0; j < k; ++j)
    {
        int u; cin >> u; --u;
        rem[u] = fortress[u] = true;
    }

    vector<vector<int>> E(n);
    vector<int> deg(n, 0), rdeg(n, 0);

    for (int j = 0; j < m; ++j)
    {
        int u, v; cin >> u >> v; --u, --v;
        E[u].push_back(v), E[v].push_back(u);

        deg[u] += 1, deg[v] += 1;
        rdeg[u] += !rem[v], rdeg[v] += !rem[u];
    }

    struct Data
    {
        double key;
        int v;
        Data(double key, int v) : key(key), v(v) { }
        bool operator<(const Data& rhs) const { return key > rhs.key; }
    };
    priority_queue<Data> pq;

    for (int u = 0; u < n; ++u) if (not rem[u])
    {
        double ratio = 1.0 * rdeg[u] / deg[u];
        pq.emplace(ratio, u);
    }

    double opt = -1e300;
    int until = 0;

    vector<int> memo;

    for (int i = 0; i < n - k; ++i)
    {
        while (rem[pq.top().v]) pq.pop();

        if (chmax(opt, pq.top().key)) until = i;

        int u = pq.top().v; pq.pop();

        rem[u] = true;
        memo.push_back(u);

        for (auto v : E[u]) if (not rem[v])
        {
            --rdeg[v];
            pq.emplace(1.0 * rdeg[v] / deg[v], v);
        }
    }

    memo.resize(until);
    sort(all(memo));

    vector<int> ans;

    for (int u = 0; u < n; ++u)
    {
        if (not fortress[u] && not binary_search(all(memo), u)) ans.push_back(u);
    }

    int r = size(ans);

    cout << r << endl;

    for (int i = 0; i < r; ++i) cout << ans[i] + 1 << "\n "[i + 1 < r];

    exit(0);
}