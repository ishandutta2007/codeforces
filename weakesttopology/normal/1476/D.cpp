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

    string s;
    cin >> s;

    vector<array<int, 2>> dpleft(n + 1, { 1, 1 }), dpright(n + 1, { 1, 1 });

    for (int i = 1; i <= n; ++i)
    {
        int x = s[i - 1] == 'L' ? 0 : 1;
        dpleft[i][x] += dpleft[i - 1][x ^ 1];
    }

    for (int i = n - 1; i >= 0; --i)
    {
        int x = s[i] == 'R' ? 0 : 1;
        dpright[i][x] += dpright[i + 1][x ^ 1];
    }

    for (int i = 0; i <= n; ++i)
    {
        int res = dpleft[i][0] + dpright[i][0] - 1;
        cout << res << "\n "[i < n];
    }
}

int main()
{ _
    int t;
    cin >> t;
    while (t--) solve();
    exit(0);
}