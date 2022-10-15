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

constexpr int nmax = 700, dp_size = nmax * nmax * 2;
int dp[nmax][nmax][2], g[nmax + 1][nmax + 1];

int main()
{ _
    fill(&dp[0][0][0], &dp[0][0][0] + dp_size, -1);

    int n; cin >> n;

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    a.push_back(0);

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            g[i][j] = gcd(a[i], a[j]);

    function<bool(int, int, int)> solve = [&](int l, int r, int b)
    {
        int rt = b ? r + 1 : l - 1; 

        if (r < l || (l == r && g[rt][l] > 1)) return true;

        int& memo = dp[l][r][b];

        if (memo != -1) return !!memo;

        for (int i = l; i <= r; ++i) if (g[rt][i] > 1)
        {
            if (solve(l, i - 1, 1) && solve(i + 1, r, 0))
            {
                memo = 1;
                return true;
            }
        } 

        memo = 0;
        return false;
    };

    string ans = "No";

    for (int i = 0; i < n; ++i)
    {
        if (solve(0, n - 1, 1))
        {
            ans = "Yes";
            break;
        }
    }

    cout << ans << endl;

    exit(0);
}