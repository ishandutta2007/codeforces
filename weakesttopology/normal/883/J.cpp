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
    int n, m; cin >> n >> m;

    vector a(n, 0), b(m, 0), p(m, 0);

    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    for (auto& x : p) cin >> x;

    auto suffixmax = a;

    for (int i = n - 2; i >= 0; --i)
        suffixmax[i] = max(a[i], suffixmax[i + 1]);

    vector B(n, vector(0, 0));

    for (int j = 0; j < m; ++j)
    {
        auto iter = lower_bound(rall(suffixmax), b[j]);
        if (iter == rend(suffixmax)) continue;
        int pos = n - 1 - (int)distance(rbegin(suffixmax), iter);
        B[pos].push_back(j);
    }

    priority_queue<ll> pq;

    ll sum = 0LL;

    int ans = 0;

    for (int i = 0; i < n; ++i)
    {
        sum += a[i];

        for (auto j : B[i])
        {
            while (sum < p[j] && not empty(pq) && pq.top() > p[j])
            {
                sum += pq.top(); pq.pop();
                ans -= 1;
            }
            if (sum >= p[j])
            {
                sum -= p[j], ans += 1;
                pq.push(p[j]);
            }
        }
    }

    cout << ans << endl;

    exit(0);
}