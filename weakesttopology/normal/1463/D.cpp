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

int solve()
{
    int n; cin >> n;

    vector b(n, 0);

    for (auto& x : b) cin >> x;

    vector nb(2 * n, 0); iota(all(nb), 1);

    auto pred = [&b](int x){ return binary_search(all(b), x); };
    nb.erase(remove_if(all(nb), pred), end(nb));

    int l = -INF, r = INF;

    for (int i = 0; i < n; ++i)
    {
        int x = i;

        for (int z = n; z; z >>= 1)
            while (x + z <= n && b[i] < nb[n - (x + z) + i]) x += z;

        r = min(r, x);
    }

    for (int i = 0; i < n; ++i)
    {
        int x = n - i;

        for (int z = n; z; z >>= 1)
            while (x - z >= 0 && nb[i] < b[(x - z) + i]) x -= z;

        l = max(l, x);
    }

    debug(l);
    debug(r);

    return max(0, r - l + 1);
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}