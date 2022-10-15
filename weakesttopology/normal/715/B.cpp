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

bool chmin(auto& x, auto y)
{
    return y < x ? x = y, true : false;
}

template<typename T>
auto dijkstra(int s, const auto& E)
{
    vector<T> dist(size(E), T(LINF)); dist[s] = T(0);
    struct Data
    {
        T key; int v;
        Data(T key, int v) : key(key), v(v) { }
        bool operator<(const Data& rhs) const { return rhs.key < key; }
    };
    priority_queue<Data> pq; pq.emplace(dist[s], s);
    while (!pq.empty())
    {
        auto [d, u] = pq.top(); pq.pop();
        if (dist[u] < d) continue;
        for (auto [v, w] : E[u])
            if (chmin(dist[v], dist[u] + w)) pq.emplace(dist[v], v);
    }
    return dist;
}

void fail(string s = "failing")
{
    debug(s);
    cout << "NO" << endl;
    exit(0);
}

int main()
{ _
    int n, m; cin >> n >> m;

    ll L; cin >> L;

    int src, snk; cin >> src >> snk;

    const ll maxweight = 1e9;

    vector<pair<int, int>> edges(m);
    vector<ll> weight(m);
    vector<bool> var(m, false);

    vector<vector<pair<int, ll&>>> E(n);

    for (int j = 0; j < m; ++j)
    {
        auto& [u, v] = edges[j];
        cin >> u >> v;

        ll w; cin >> w;

        if (w == 0)
        {
            weight[j] = 1, var[j] = true;
        }
        else
        {
            weight[j] = w;
        }

        E[u].emplace_back(v, weight[j]);
        E[v].emplace_back(u, weight[j]);
    }

    // check minimum
    {
        auto dist_chk = dijkstra<ll>(src, E);
        if (dist_chk[snk] > L) fail("large minimum");
    }
    // check maximum
    {
        for (int j = 0; j < m; ++j) if (var[j]) weight[j] = maxweight;
        auto dist_chk = dijkstra<ll>(src, E);
        if (dist_chk[snk] < L) fail("small maximum");
        for (int j = 0; j < m; ++j) if (var[j]) weight[j] = 1;
    }

    int k = -1;

    ll prev_dist = dijkstra<ll>(src, E)[snk];

    if (prev_dist != L)
    {
        for (int j = 0; j < m; ++j) if (var[j])
        {
            weight[j] = maxweight;
            auto dist = dijkstra<ll>(src, E);
            if (dist[snk] >= L)
            {
                k = j;
                break;
            }
            else
            {
                prev_dist = dist[snk];
            }
        }

        assert(k != -1);
        weight[k] = 1 + L - prev_dist;
    }

    cout << "YES" << endl;

    for (int j = 0; j < m; ++j)
    {
        auto [u, v] = edges[j];
        cout << u << " " << v << " " << weight[j] << endl;
    }

    exit(0);
}