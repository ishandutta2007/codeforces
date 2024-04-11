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
    int n; cin >> n;

    vector a(n, 0LL);

    for (auto& x : a) cin >> x;

    ll sum = accumulate(all(a), 0LL);

    ll q = max(*max_element(all(a)), (sum + (n - 2)) / (n - 1));

    ll ans = (n - 1) * q - sum;

    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}