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
    int n;
    cin >> n;

    map<pair<int, int>, int> freq;

    ll res = 0;

    for (int i = 0; i < n; ++i)
    {
        int x, y, u, v;
        cin >> x >> y >> u >> v;

        int dx = u - x, dy = v - y;
        int g = gcd(dx, dy);

        dx /= g, dy /= g;

        res += freq[pair(-dx, -dy)];
        freq[pair(dx, dy)] += 1;
    }

    return res;
}

int main()
{ _
    int t;
    cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}