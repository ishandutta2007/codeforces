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
    for (auto& x : a) cin >> x;

    if (n == 1)
    {
        cout << a[0] << endl;
        exit(0);
    }

    vector<ll> prefix(n, 0), suffix(n, 0);

    for (int i = 0; i < n; ++i)
    {
        prefix[i] = a[i] + (i > 1 ? prefix[i - 2] : 0);
    }
    for (int i = n - 1; i >= 0; --i)
    {
        suffix[i] = a[i] + (i + 2 < n ? suffix[i + 2] : 0);
    }

    ll ans = suffix[0];

    for (int i = 0; i + 1 < n; ++i)
    {
        ans = max(ans, prefix[i] + suffix[i + 1]);
    }

    cout << ans << endl;

    exit(0);
}