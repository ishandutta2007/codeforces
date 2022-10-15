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

int main()
{ _
    int n;
    ll k;
    cin >> n >> k;

    if (k < n / 2 || (n == 1 && k > 0))
    {
        cout << -1 << endl;
    }
    else if (n == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        ll x = k - (n / 2 - 1), y = 2 * x;
        cout << x << " " << y;
        for (int i = 2; i < n; ++i)
        {
            ll x = (int)3e8 + i;
            cout << " " << x;
        }
        cout << endl;
    }

    exit(0);
}