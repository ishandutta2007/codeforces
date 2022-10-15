#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

void solve()
{
    int n; cin >> n;
    vector<string> G(n);
    for (auto& s : G) cin >> s;

    vector op(0, pair(0, 0));

    bool S = G[0][1] == G[1][0];
    bool F = G[n - 1][n - 2] == G[n - 2][n - 1];

    if (S && F)
    {
        if (G[0][1] == G[n - 1][n - 2])
        {
            op.emplace_back(1, 2), op.emplace_back(2, 1);
        }
    }
    else if (S && not F)
    {
        if (G[0][1] == G[n - 1][n - 2])
            op.emplace_back(n, n - 1);
        else
            op.emplace_back(n - 1, n);
    }
    else if (not S && F)
    {
        if (G[0][1] == G[n - 1][n - 2])
            op.emplace_back(1, 2);
        else
            op.emplace_back(2, 1);
    }
    else
    {
        if (G[0][1] == '1')
            op.emplace_back(1, 2);
        if (G[1][0] == '1')
            op.emplace_back(2, 1);
        if (G[n - 1][n - 2] == '0')
            op.emplace_back(n, n - 1);
        if (G[n - 2][n - 1] == '0')
            op.emplace_back(n - 1, n);
    }

    cout << size(op) << endl;
    for (auto [i, j] : op)
    {
        cout << i << " " << j << endl;
        char& c = G[i - 1][j - 1];
        c = c == '0' ? '1' : '0';
    }

    assert(size(op) <= 2);
    // for (auto& s : G)
    //     debug(s);
}

int main()
{ _
    int t; cin >> t;
    while (t--) solve();
    exit(0);
}