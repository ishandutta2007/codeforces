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

int solve()
{
    int n; cin >> n;

    vector a(n, 0);

    for (auto& x : a) cin >> x;

    int ans = 0;

    for (int i = 1; i < n; ++i)
    {
        int d = max(0, a[i - 1] - a[i]);

        if (d > 0)
        {
            ans = max(ans, 31 - __builtin_clz(d) + 1);
            a[i] += d;
        }
    }

    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}