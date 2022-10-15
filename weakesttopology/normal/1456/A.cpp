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

ll solve()
{
    int n, p, k; cin >> n >> p >> k;

    string s; cin >> s;
    s.push_back('1');

    ll x, y; cin >> x >> y;

    vector<ll> dp(n + 1, 0);

    ll ans = LINF;

    for (int i = n - 1; i >= p - 1; --i)
    {
        int j = min(n, i + k);
        dp[i] = (s[i] != '1') + dp[j];
        ans = min(ans, x * dp[i] +  (i - (p - 1)) * y);
    }

    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}