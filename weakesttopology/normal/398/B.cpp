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

const double eps = 1e-9;

int main()
{ _
    int n, m; cin >> n >> m;

    vector visrow(n, 0), viscol(n, 0);

    for (int j = 0; j < m; ++j)
    {
        int r, c; cin >> r >> c; --r, --c;
        visrow[r] = viscol[c] = 1;
    }

    int sr = accumulate(all(visrow), 0), sc = accumulate(all(viscol), 0);

    debug(sr);
    debug(sc);

    vector prob(n + 1, vector(n + 1, 0.0)), cost(n + 1, vector(n + 1, 0.0));

    prob[sr][sc] = 1.0;

    cerr << setprecision(2) << fixed;

    for (int i = sr; i <= n; ++i)
    {
        for (int j = sc; j <= n; ++j)
        {
            if (prob[i][j] < eps || min(i, j) == n) continue;

            cost[i][j] /= prob[i][j];

            cost[i][j] += 1 / (1 - double(i * j) / (n * n));

            double p[3] =
            {
                double((n - i) * j) / (n * n - i * j),
                double((n - j) * i) / (n * n - i * j),
                double((n - i) * (n - j)) / (n * n - i * j)
            };

            if (i < n)
            {
                cost[i + 1][j] += cost[i][j] * p[0] * prob[i][j];
                prob[i + 1][j] += p[0] * prob[i][j];
            }
            if (j < n)
            {
                cost[i][j + 1] += cost[i][j] * p[1] * prob[i][j];
                prob[i][j + 1] += p[1] * prob[i][j];
            }
            if (i < n && j < n)
            {
                cost[i + 1][j + 1] += cost[i][j] * p[2] * prob[i][j];
                prob[i + 1][j + 1] += p[2] * prob[i][j];
            }
        }
    }

    debug(prob[n][n]);

    double ans = cost[n][n];

    cout << setprecision(20) << fixed << ans << endl;

    exit(0);
}