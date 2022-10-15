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

ll solve()
{
    int n, k; cin >> n >> k;

    vector a(n, 0LL);

    for (int i = 0; i < n; ++i) cin >> a[i];

    // if (k == n - 1) return accumulate(all(a), 0LL);

    sort(all(a)), reverse(all(a));

    for (int i = 1; i <= k; ++i) a[0] += a[i];

    return a[0];
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}