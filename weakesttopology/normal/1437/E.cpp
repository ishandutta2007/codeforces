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

void fail()
{
    cout << -1 << endl;
    exit(0);
}

int main()
{ _
    int n, k; cin >> n >> k;

    vector a(n + 2, 0);

    a[0] = -INF, a[n + 1] = INF - (n + 1);

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i]; a[i] -= i;
    }

    vector b(k + 2, 0);

    b[k + 1] = n + 1;

    for (int j = 1; j <= k; ++j) cin >> b[j];

    k += 2, n += 2;

    for (int j = 0; j + 1 < k; ++j)
        if (a[b[j + 1]] < a[b[j]]) fail();

    vector L(n, INF);

    auto solve = [&](int l, int r)
    {
        L[0] = a[l];

        for (int i = l + 1; i < r; ++i)
        {
            auto iter = upper_bound(all(L), a[i]);

            int idx = (int)distance(begin(L), iter);

            if (idx > 0) L[idx] = a[i];
        }

        auto iter = upper_bound(all(L), a[r]);

        int res = (int)distance(begin(L), iter) + 1;

        // fix this
        fill(begin(L), begin(L) + r - l + 1, INF);

        return res;
    };

    int ans = n - k;

    for (int j = 0; j + 1 < k; ++j)
        ans -= solve(b[j], b[j + 1]) - 2;

    cout << ans << endl;

    exit(0);
}