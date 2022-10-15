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

int main()
{ _
    int n, k; cin >> n >> k;

    vector a(n, 0LL);

    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(all(a)); reverse(all(a));

    auto sq = [](ll x) { return x * x; };
    auto cost = [&sq](ll x, ll k)
    {
        return (k - (x % k)) * sq(x / k) + (x % k) * sq(x / k + 1);
    };

    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for (int j = 0; j < k - n; ++j) pq.push(0LL);

    ll ans = 0LL;

    for (auto x : a)
    {
        ans += cost(x, 1);
        if (pq.empty()) continue;
        for (int j = 1; pq.top() < (cost(x, j) - cost(x, j + 1)) && j <= k - n; ++j)
        {
            pq.pop();
            pq.push(cost(x, j) - cost(x, j + 1));
        }
    }

    while (not pq.empty())
    {
        ans -= pq.top(); pq.pop();
    }

    cout << ans << endl;

    exit(0);
}