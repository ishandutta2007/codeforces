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

void solve()
{
    int n; cin >> n;

    vector<pair<ll, ll>> op;

    ll cur = n;

    for (ll x = n - 1; x >= 3; --x)
    {
        if (x * x <= cur)
        {
            op.emplace_back(n, x);
            cur = (cur + (x - 1)) /x;
        }
        op.emplace_back(x, n);
    }

    while (cur > 1)
    {
        op.emplace_back(n, 2);
        cur = (cur + 1) / 2;
    }

    cout << size(op) << endl;

    for (auto [x, y] : op) cout << x << " " << y << endl;
}

int main()
{ _
    int t; cin >> t;
    while (t--) solve();
    exit(0);
}