#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;
using ld = long double;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main()
{ _
    int m, n;
    cin >> m >> n;

    ld E = 0;

    for (int x = 1; x <= m; ++x)
    {
        E += 1 - powl(1.0 * (x - 1) / m, n);
    }

    cout << setprecision(10) << fixed;
    cout << E << endl;

    exit(0);
}