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

bool chmin(auto& x, auto y) { return y < x ? (x = y, true) : false; }

constexpr int D = 4;
constexpr int dx[D] = { +1, -1, +0, -0 };
constexpr int dy[D] = { +0, -0, +1, -1 };

template<typename T>
struct Dinic
{
    struct Edge
    {
        int from, to;
        T cap, flow = 0;
        T free() { return cap - flow; }
        Edge(int u, int v, T cap) : from(u), to(v), cap(cap) {}
    };
    vector<Edge> edges;
    const T inf = numeric_limits<T>::max();
    int n, m = 0;
    vector<vector<int>> E;
    vector<int> level, ptr;
    Dinic(int n) : n(n)
    {
        E.resize(n), level.resize(n), ptr.resize(n);
    }
    void add_edge(int u, int v, T cap)
    {
        if (cap <= 0) return;
        edges.emplace_back(u, v, cap);
        edges.emplace_back(v, u, 0);
        E[u].push_back(m++);
        E[v].push_back(m++);
    }
    bool bfs(int s, int t)
    {
        fill(all(level), 0); level[s] = 1;
        static queue<int> q; q.push(s);
        while (not q.empty())
        {
            int u = q.front(); q.pop();
            for (auto idx : E[u])
            {
                int v = edges[idx].to;
                if (level[v] != 0 || edges[idx].free() <= 0) continue;
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
        return level[t] != 0;
    }
    T push(int u, int t, T pushed)
    {
        if (u == t || pushed == 0) return pushed;
        for (int& idx = ptr[u]; idx < size(E[u]); ++idx)
        {
            auto &edge = edges[E[u][idx]], &back = edges[E[u][idx] ^ 1];
            if (level[edge.to] != level[u] + 1 || edge.free() <= 0) continue;
            T pushing = push(edge.to, t, min(pushed, edge.free()));
            if (pushing == 0) continue;
            edge.flow += pushing, back.flow -= pushing;
            return pushing;
        }
        return 0;
    }
    T flow(int s, int t)
    {
        for (auto& edge : edges) edge.flow = 0;
        T f = 0;
        while (bfs(s, t))
        {
            fill(all(ptr), 0);
            while (T pushed = push(s, t, inf)) f += pushed;
        }
        return f;
    }
};

int main()
{ _
    int n, t; cin >> n >> t;

    vector<string> labs(n), rescue(n);

    for (auto& s : labs) cin >> s;
    for (auto& s : rescue) cin >> s;

    int xs = -1, ys = -1;

    vector<pair<int, int>> pts;

    for (int x = 0; x < n; ++x)
        for (int y = 0; y < n; ++y)
        {
            if (isdigit(labs[x][y]))
                pts.emplace_back(x, y);
            if (labs[x][y] == 'Z')
                xs = x, ys = y;
        }

    auto valid = [&](int x, int y) { return 0 <= min(x, y) && max(x, y) < n; };
    auto id = [&](int x, int y) { return x * n + y; };

    vector<vector<int>> E(n * n);

    pts.emplace_back(xs, ys);

    for (auto [x, y] : pts) 
        for (int d = 0; d < D; ++d)
        {
            int xnxt = x + dx[d], ynxt = y + dy[d];
            if (not valid(xnxt, ynxt) || not isdigit(labs[xnxt][ynxt])) continue;
            E[id(x, y)].push_back(id(xnxt, ynxt));
        }

    pts.pop_back();

    auto bfs = [&](int s)
    {
        vector<int> dist(n * n, INF);
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        while (not empty(q))
        {
            int u = q.front(); q.pop();
            for (auto v : E[u])
            {
                if (chmin(dist[v], dist[u] + 1)) q.push(v);
            }
        }
        return dist;
    };

    vector<vector<int>> dist(n * n);

    for (auto [x, y] : pts)
    {
        int u = id(x, y);
        dist[u] = bfs(u);
    }
    dist[id(xs, ys)] = bfs(id(xs, ys));

    Dinic<int> dinic(2 * n * n + 2);
    const int src = 2 * n * n, snk = 2 * n * n + 1;

    for (auto [x, y] : pts)
        for (auto [xt, yt] : pts)
        {
            int u = id(x, y), v = id(xt, yt);

            bool good = (u == v);

            for (int d = 0; d < D; ++d)
            {
                int xnxt = xt + dx[d], ynxt = yt + dy[d];
                if (not valid(xnxt, ynxt) || not isdigit(labs[xnxt][ynxt])) continue;
                int w = id(xnxt, ynxt);
                if (dist[id(xs, ys)][w] > dist[u][w])
                {
                    good = true;
                    break;
                }
            }

            if (good && dist[u][v] <= min(t, dist[id(xs, ys)][v]))
            {
                dinic.add_edge(u, n * n + v, INF);
            }
        }

    for (auto [x, y] : pts)
    {
        int u = id(x, y);
        dinic.add_edge(src, u, labs[x][y] - '0');
        dinic.add_edge(n * n + u, snk, rescue[x][y] - '0');
    }

    int ans = dinic.flow(src, snk);

    cout << ans << endl;

    exit(0);
}