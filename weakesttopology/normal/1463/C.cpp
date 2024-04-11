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

ll solve()
{
    int n; cin >> n;

    vector t(n + 1, LINF), x(n, 0LL);

    for (int i = 0; i < n; ++i) cin >> t[i] >> x[i];

    ll pos = 0, target = 0, ans = 0;

    for (int i = 0; i < n; ++i)
    {
        if (pos == target) target = x[i];

        ll delta = min(t[i + 1] - t[i], abs(pos - target));
        ll dir = pos < target ? +1 : -1;

        ll L = pos, R = pos + dir * delta;

        if (L > R) swap(L, R);

        ans += (L <= x[i] && x[i] <= R);

        pos += dir * delta;
    }

    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}