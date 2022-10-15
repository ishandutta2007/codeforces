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

const int T = 2;
const int dx[T] = { +1, +0 };
const int dy[T] = { +0, +1 };

int main()
{ _
    int n, m; cin >> n >> m;

    vector<string> grid(n);

    for (auto& s : grid) cin >> s;

    auto valid = [&](int x, int y) { return 0 <= min(x, y) && x < n && y < m; };

    if (grid[0][0] != grid[n - 1][m - 1])
    {
        cout << 0 << endl;
        exit(0);
    }

    constexpr int m_max = 500;
    vector<int> dp__(n * m_max, 0), dpnxt__(n * m_max, 0);
    auto dp = (int(*)[m_max])&dp__[0], dpnxt = (int(*)[m_max])&dpnxt__[0];

    dp[0][n - 1] = 1;

    const int mod = 1e9 + 7;

    int diam = n + m - 2;

    for (int i = 0; i < diam / 2; ++i)
    {
        for (int xs = 0; xs <= i; ++xs) for (int xt = n - 1; xt >= n - 1 - i; --xt)
        {
            int ys = i - xs, yt = m - 1 - (i - (n - 1 - xt));

            if (not valid(xs, ys) || not valid(xt, yt) || dp[xs][xt] == 0) continue;

            for (int e = 0; e < T; ++e)
            {
                int nxs = xs + dx[e], nys = ys + dy[e];
                if (not valid(nxs, nys)) continue;

                for (int f = 0; f < T; ++f)
                {
                    int nxt = xt - dx[f], nyt = yt - dy[f];
                    if (not valid(nxt, nyt) || grid[nxs][nys] != grid[nxt][nyt]) continue;

                    (dpnxt[nxs][nxt] += dp[xs][xt]) %= mod;
                }
            }
        }

        swap(dp, dpnxt), swap(dp__, dpnxt__), fill(all(dpnxt__), 0);
    }

    int ans = 0;

    if ((diam - 1) % 2)
    {
        for (int xs = 0; xs < n; ++xs)
        {
            int ys = diam / 2 - xs;
            if (valid(xs, ys)) (ans += dp[xs][xs]) %= mod;
        }
    }
    else
    {
        for (int xs = 0; xs < n; ++xs)
        {
            int ys = diam / 2 - xs;
            for (int e = 0; e < T; ++e)
            {
                int nxs = xs + dx[e], nys = ys + dy[e];
                if (valid(nxs, nys)) (ans += dp[xs][nxs]) %= mod;
            }
        }
    }

    cout << ans << endl;

    exit(0);
}