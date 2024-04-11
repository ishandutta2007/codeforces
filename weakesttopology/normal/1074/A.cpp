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
    int n, m;
    cin >> n >> m;

    const int N = 1e9;

    vector<int> v(n);
    for (auto& x : v) cin >> x;
    v.push_back(N);

    sort(all(v));

    vector<int> a(n + 2, 0);

    for (int j = 0; j < m; ++j)
    {
        int l, r, y;
        cin >> l >> r >> y;
        if (l == 1)
        {
            auto iter = upper_bound(all(v), r);
            int idx = (int)distance(begin(v), iter);
            a[0] += 1, a[idx] -= 1;
        }
    }

    int res = a[0];

    for (int x = 1; x <= n; ++x)
    {
        a[x] += a[x - 1];
        res = min(res, x + a[x]);
    }

    cout << res << endl;

    exit(0);
}