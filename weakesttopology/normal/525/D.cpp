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

constexpr int K = 8;
constexpr int kx[K] = { +1, +1, +0, -1, -1, -1, +0, +1 };
constexpr int ky[K] = { +0, +1, +1, +1, +0, -1, -1, -1 };

int main()
{ _
    int n, m; cin >> n >> m;

    vector<string> grid(n);
    for (auto& s : grid) cin >> s;

    auto valid = [&](int x, int y) { return 0 <= min(x, y) && x < n && y < m; };
    auto check_corner = [&](int x, int y)
    {
        if (not valid(x, y) || grid[x][y] == '.') return false;
        char ch[8];
        fill(all(ch), 'x');
        for (int k = 0; k < K; ++k)
        {
            int nx = x + kx[k], ny = y + ky[k];
            if (valid(nx, ny)) ch[k] = grid[nx][ny];
        }
        for (int k = 1; k < K; k += 2)
        {
            bool good = true;
            for (auto d : { (k - 1), k, (k + 1) % K })
            {
                if (ch[d] != '.') good = false;
            }
            if (good) return true;
        }
        return false;
    };

    queue<pair<int, int>> q;

    for (int x = 0; x < n; ++x)
        for (int y = 0; y < m; ++y)
        {
            if (grid[x][y] == '.') q.emplace(x, y);
        }

    vector<vector<int>> vis(n, vector<int>(m, 0));

    while (not empty(q))
    {
        auto [x, y] = q.front(); q.pop();
        if (vis[x][y]++) continue;
        for (int k = 0; k < K; ++k)
        {
            int nx = x + kx[k], ny = y + ky[k];
            if (not valid(nx, ny)) continue;
            if (check_corner(nx, ny)) grid[nx][ny] = '.';
            if (grid[nx][ny] == '.') q.emplace(nx, ny);
        }
    }

    for (auto& s : grid) cout << s << endl;

    exit(0);
}