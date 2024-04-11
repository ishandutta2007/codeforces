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

using ld = long double;

const ld PI = acos(-1);

int main()
{ _
    int n; cin >> n;

    vector<pair<ld, int>> theta(n);

    for (int i = 0; i < n; ++i)
    {
        int x, y; cin >> x >> y;
        theta[i] = pair(atan2l(y, x) + PI, i);
    }

    sort(all(theta));

    ld opt = 1e300;
    int a = -1, b = -1;

    for (int i = 0; i < n; ++i)
    {
        int j = (i + 1) % n;

        ld alpha = theta[i].first, beta = theta[j].first;

        ld cur = min({ abs(alpha - beta), abs(alpha + 2 * PI - beta), abs(alpha - 2 * PI - beta) });

        if (cur < opt) a = theta[i].second, b = theta[j].second, opt = cur;
    }

    debug(opt);

    cout << a + 1 << " " << b + 1 << endl;

    exit(0);
}