#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
long long x[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    long long p = x[(n + 1) >> 1];
    int ind = 1;
    while (ind <= n && x[ind] <= p) ++ind; --ind;
    long long ans = 0;
    for (int i = 1; i <= ind; i += m) ans += 2LL * abs(p - x[i]);
    for (int i = n; i > ind; i -= m) ans += 2LL * abs(p - x[i]);
    cout << ans << endl;
    return 0;
}