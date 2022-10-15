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

long double solve()
{
    int n;
    cin >> n;

    vector<ll> a, b;

    for (int i = 0; i < 2 * n; ++i)
    {
        ll x, y;
        cin >> x >> y;
        if (x == 0) b.push_back(abs(y));
        if (y == 0) a.push_back(abs(x));
    }

    sort(all(a)), sort(all(b));

    long double res = 0;

    for (int i = 0; i < n; ++i)
    {
        res += sqrtl(a[i] * a[i] + b[i] * b[i]);
    }

    return res;
}

int main()
{ _
    int t;
    cin >> t;
    cout << setprecision(10) << fixed;
    while (t--) cout << solve() << endl;
    exit(0);
}