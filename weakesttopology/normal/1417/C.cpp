#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) (X).begin(), (X).end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

void solve()
{
    int n; cin >> n;
    vector a(n, 0);
    for (auto& x : a)
    {
        cin >> x; --x;
    }

    vector pos(n, vector(1, -1));
    for (int i = 0; i < n; ++i)
        pos[a[i]].push_back(i);
    for (int i = 0; i < n; ++i)
        pos[i].push_back(n);

    vector d(n, -1);
    for (int i = 0; i < n; ++i)
        for (int j = 1; j < sz(pos[i]); ++j)
            d[i] = max(d[i], pos[i][j] - pos[i][j - 1]);

    vector ans(n, INF);
    for (int i = n - 1; i >= 0; --i)
        if (d[i] <= n) ans[d[i] - 1] = i + 1;
    for (int i = 1; i < n; ++i)
        ans[i] = min(ans[i], ans[i - 1]);
    for (int i = 0; i < n; ++i)
        if (ans[i] == INF) ans[i] = -1;

    for (auto x : ans)
        cout << x << " ";
    cout << endl;
}

int main()
{ _
    int t; cin >> t;
    while (t--) solve();
    exit(0);
}