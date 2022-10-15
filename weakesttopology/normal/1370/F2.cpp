#include "bits/stdc++.h"

using namespace std;

#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

constexpr int max_queries = 11;

pair<int, int> query(const vector<int>& q)
{
    if (empty(q)) while (true);

    cout << "? " << size(q);
    for (auto u : q) cout << " " << u + 1;
    cout << endl;

    int x, d; cin >> x >> d; --x;

    return pair<int, int>(x, d);
}

bool chmin(auto& x, auto y) { return y < x ? (x = y, true) : false; }

vector<int> bfs(int s, const auto& E)
{
    vector<int> dist(size(E), INF);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while (not empty(q))
    {
        int u = q.front(); q.pop();
        for (auto v : E[u]) if (chmin(dist[v], dist[u] + 1)) q.push(v);
    }
    return dist;
}

string solve()
{
    int n; cin >> n;

    vector<vector<int>> E(n);

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v; cin >> u >> v; --u, --v;
        E[u].push_back(v), E[v].push_back(u);
    }

    vector<int> h(n, -1);

    function<void(int)> dfs = [&](int u)
    {
        for (auto v : E[u]) if (h[v] == -1)
        {
            h[v] = h[u] + 1;
            dfs(v);
        }
    };

    int root = -1;
    {
        auto dist = bfs(0, E);
        int v = (int)distance(begin(dist), max_element(all(dist)));

        dist = bfs(v, E);

        int diam = *max_element(all(dist));

        for (int u = 0; u < n; ++u)
        {
            if (dist[u] == (diam + 1) / 2)
            {
                root = u;
                break;
            }
        }
    }

    debug(root);

    h[root] = 0;
    dfs(root);

    vector<pair<int, int>> queries;

    int prv = INF, u = -1;

    {
        vector<int> q(n);
        iota(all(q), 0);
        tie(u, prv) = query(q);
    }

    auto fix = [&](int level)
    {
        vector<int> q;
        for (int u = 0; u < n; ++u)
        {
            if (level <= h[u]) q.push_back(u);
        }
        if (empty(q)) return false;
        auto [x, d] = query(q);
        queries.emplace_back(x, d);
        bool good = false;
        if (prv >= d) u = x, prv = d, good = true;
        return good;
    };

    const int max_j = __builtin_clz(1) - __builtin_clz(*max_element(all(h)));

    int level = 0;
    for (int j = max_j; j >= 0; --j)
    {
        if (fix(level + (1 << j)))
        {
            level += 1 << j;
        }
    }

    debug(u);

    auto dist = bfs(u, E);

    vector<int> q;

    for (int v = 0; v < n; ++v)
    {
        if (dist[v] == prv)
        {
            q.push_back(v);
        }
    }

    int v = query(q).first;

    string res = "! ";
    res += to_string(u + 1) + " " + to_string(v + 1);

    return res;
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string res = solve();
        cout << res << endl;
        string verdict; cin >> verdict;
        assert(verdict == "Correct");
    }
    exit(0);
}