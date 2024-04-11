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

int main()
{ _
    constexpr int K = 26, tmax = 250;

    int n, q; cin >> n >> q;

    string s; cin >> s;

    vector<array<int, K>> nxt(n + 1);
    array<int, K> last;
    fill(all(last), INF);

    for (int i = n - 1; i >= 0; --i)
    {
        int ch = s[i] - 'a';
        last[ch] = i;
        nxt[i] = last;
    }

    int dp[tmax + 1][tmax + 1][tmax + 1];

    for (int x = 0; x <= tmax; ++x)
        for (int y = 0; y <= tmax; ++y)
            for (int z = 0; z <= tmax; ++z)
                dp[x][y][z] = INF;

    dp[0][0][0] = 0;

    vector<vector<int>> t(3);
    int tsize[3] = { 0, 0, 0 };

    auto run = [&](int x0, int y0, int z0)
    {
        for (int x = x0; x <= tsize[0]; ++x)
            for (int y = y0; y <= tsize[1]; ++y)
                for (int z = z0; z <= tsize[2]; ++z)
                {
                    int i = dp[x][y][z];
                    if (i >= n) continue;
                    if (x < tsize[0]) chmin(dp[x + 1][y][z], nxt[i][t[0][x]] + 1);
                    if (y < tsize[1]) chmin(dp[x][y + 1][z], nxt[i][t[1][y]] + 1);
                    if (z < tsize[2]) chmin(dp[x][y][z + 1], nxt[i][t[2][z]] + 1);
                }
    };

    while (q--)
    {
        char type; cin >> type;
        int j; cin >> j; --j;

        if (type == '-')
        {
            int x0 = (j == 0 ? tsize[j] : 0);
            int y0 = (j == 1 ? tsize[j] : 0);
            int z0 = (j == 2 ? tsize[j] : 0);

            for (int x = x0; x <= tsize[0]; ++x)
                for (int y = y0; y <= tsize[1]; ++y)
                    for (int z = z0; z <= tsize[2]; ++z)
                        dp[x][y][z] = INF;

            tsize[j] -= 1;
            t[j].pop_back();
        }
        else
        {
            char c; cin >> c;

            tsize[j] += 1;
            t[j].push_back(c - 'a');

            int x0 = (j == 0 ? tsize[j] - 1 : 0);
            int y0 = (j == 1 ? tsize[j] - 1 : 0);
            int z0 = (j == 2 ? tsize[j] - 1 : 0);

            run(x0, y0, z0);

        }
        string ans = dp[tsize[0]][tsize[1]][tsize[2]] <= n ? "YES" : "NO";
        cout << ans << endl;
    }

    exit(0);
}