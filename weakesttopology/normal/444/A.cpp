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
    int n, m; cin >> n >> m;

    vector<int> x(n);

    for (int u = 0; u < n; ++u) cin >> x[u];

    double ans = 0.0;

    for (int j = 0; j < m; ++j)
    {
        int u, v, w; cin >> u >> v >> w; --u, --v;
        ans = max(ans, double(x[u] + x[v]) / double(w));
    }

    cout << setprecision(20) << fixed;
    cout << ans << endl;

    exit(0);
}