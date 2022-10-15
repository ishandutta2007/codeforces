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

void solve()
{
    int n;
    cin >> n;

    constexpr int nmax = 100;
    int res[nmax][nmax]{};

    int k = (n - 1) / 2;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            int x = i, y = (i + 1 + j) % n;
            res[x][y] = +1, res[y][x] = -1;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            cout << res[i][j] << " ";
        }
    }
    cout << endl;
}

int main()
{ _
    int t;
    cin >> t;
    while (t--) solve();
    exit(0);
}