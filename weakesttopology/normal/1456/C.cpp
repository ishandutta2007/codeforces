#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main()
{ _
    int n, k; cin >> n >> k;

    vector<ll> a(n);
    for (auto& x : a) cin >> x;

    sort(all(a));

    ll prefix_weighted = 0, suffix_weighted = 0, suffix_sum = 0;

    for (int i = 0; i < n; ++i)
    {
        suffix_weighted += (i + 1) * a[i];
        suffix_sum += a[i];
    }

    ll ans = -LINF;

    for (int i = 0; i < n; ++i)
    {
        suffix_sum -= a[i];
        suffix_weighted -= a[i] + suffix_sum;

        prefix_weighted += a[i] * (i / (k + 1));

        ll cur = prefix_weighted + suffix_sum * (i / (k + 1)) + suffix_weighted;

        ans = max(ans, cur);
    }

    cout << ans << endl;

    exit(0);
}