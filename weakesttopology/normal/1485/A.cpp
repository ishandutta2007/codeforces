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
    int a, b;
    cin >> a >> b;

    int res = INF;

    for (int x = (b == 1); x <= 40; ++x)
    {
        int ct = 0;
        for (int z = a; z > 0; z /= (b + x), ct += 1);
        res = min(res, ct + x);
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