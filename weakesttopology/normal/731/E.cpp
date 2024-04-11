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
    int n; cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (i > 0) a[i] += a[i - 1];
    }

    vector<int> dp(n, a.back());

    int max_diff = a[n - 1];

    for (int i = n - 2; i > 0; --i)
    {
        max_diff = max(max_diff, a[i] - dp[i + 1]);
        dp[i] = max(dp[i + 1], max_diff);
    }

    int ans = *max_element(all(dp));

    cout << ans << endl;

    exit(0);
}