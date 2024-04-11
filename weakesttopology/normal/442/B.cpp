#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

const double EPS = 1e-6;

int main()
{ _
    int n; cin >> n;

    vector p(n, 0.0);

    for (auto& x : p) cin >> x;

    sort(rall(p));

    if (p[0] >= 1.0 - EPS)
    {
        cout << 1.0 << endl;
        exit(0);
    }

    double x = 1.0, y = 0.0;

    for (int i = 0; i < n && y <= 1.0; ++i)
        x *= (1 - p[i]), y += p[i] / (1 - p[i]);

    cout << setprecision(20) << fixed;
    cout << x * y << endl;

    exit(0);
}