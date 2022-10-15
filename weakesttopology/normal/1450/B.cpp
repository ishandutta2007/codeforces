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
    int n, k; cin >> n >> k;

    vector x(n, 0), y(n, 0);

    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    for (int i = 0; i < n; ++i)
    {
        int ct = 0;

        for (int j = 0; j < n; ++j)
            ct += abs(x[i] - x[j]) + abs(y[i] - y[j]) <= k;

        if (ct == n) return 1;
    }

    return -1;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}