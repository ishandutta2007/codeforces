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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> l(m), r(m);

    for (int j = 0; j < m; ++j)
    {
        cin >> l[j] >> r[j];
        --l[j], --r[j];
    }

    auto cmp = [&](int j1, int j2)
    {
        return (l[j1] + r[j1]) < (l[j2] + r[j2]);
    };

    vector<int> J(m);
    iota(all(J), 0), sort(all(J), cmp);

    vector<int> max_suffix(m + 1, 0);

    reverse(all(J));
    for (int x = 0; x + k <= n; ++x)
    {
        int cur = 0;
        for (auto j : J)
        {
            cur += max(0, min(x + k, r[j] + 1) - max(x, l[j]));
            max_suffix[j] = max(max_suffix[j], cur);
        }
    }
    reverse(all(J));

    int ans = 0;

    J.push_back(m);

    for (int x = 0; x + k <= n; ++x)
    {
        int cur = 0;
        for (int z = 0; z < m; ++z)
        {
            int j = J[z];
            cur += max(0, min(x + k, r[j] + 1) - max(x, l[j]));
            ans = max(ans, cur + max_suffix[J[z + 1]]);
        }
    }

    cout << ans << endl;

    exit(0);
}