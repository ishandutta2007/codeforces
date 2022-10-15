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

ll solve()
{
    int n, m; cin >> n >> m;

    vector<int> k(n);
    for (auto& x : k)
    {
        cin >> x; --x;
    }

    vector<int> c(m);
    for (auto& x : c) cin >> x;

    sort(rall(k));

    ll ans = 0LL;

    for (int i = 0, ptr = 0; i < n; ++i)
    {
        if (ptr < k[i])
        {
            ans += c[ptr++];
        }
        else
        {
            ans += c[k[i]];
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