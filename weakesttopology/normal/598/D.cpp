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
    int n, m, k; cin >> n >> m >> k;

    vector<string> g(n);

    for (auto& s : g) cin >> s;

    auto valid = [&](int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; };

    const int dx[4] = { +1, -1, +0, -0 };
    const int dy[4] = { +0, -0, +1, -1 };

    vector<vector<int>> vis(n, vector<int>(m, 0)), res(n, vector<int>(m));
    queue<pair<int, int>> q;

    auto bfs = [&](int i, int j)
    {
        int cnt = 0;

        q.emplace(i, j);
        while (not empty(q))
        {
            auto [x, y] = q.front(); q.pop();
            if (vis[x][y]++) continue;
            for (int t = 0; t < 4; ++t)
            {
                int nx = x + dx[t], ny = y + dy[t];
                if (valid(nx, ny))
                {
                    if (g[nx][ny] == '*') cnt += 1;
                    else if (not vis[nx][ny]) q.emplace(nx, ny);
                }
            }
        }

        q.emplace(i, j);
        while (not empty(q))
        {
            auto [x, y] = q.front(); q.pop();
            if (vis[x][y] == -1) continue;
            res[x][y] = cnt, vis[x][y] = -1;
            for (int t = 0; t < 4; ++t)
            {
                int nx = x + dx[t], ny = y + dy[t];
                if (valid(nx, ny) && vis[nx][ny] > 0) q.emplace(nx, ny);
            }
        }
    };

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (vis[i][j] == 0 && g[i][j] == '.') bfs(i, j);

    for (int z = 0; z < k; ++z)
    {
        int x, y; cin >> x >> y; --x, --y;
        cout << res[x][y] << endl;
    }

    exit(0);
}