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

string solve()
{
    ll a[3];
    cin >> a[0] >> a[1] >> a[2];

    sort(all(a));

    auto check = [&](ll x)
    {
        return x + 2 * (x / 7) <= a[0] + a[1] + a[2] && x / 7 <= a[0];
    };

    ll x = 0LL;

    for (ll z = 1e9; z > 0; z >>= 1) while (check(x + z)) x += z;

    return (x + 2 * (x / 7) == a[0] + a[1] + a[2]) && x % 7 == 0LL ? "YES" : "NO";
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}