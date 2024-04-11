#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const long double inf = 1e9;
long double e[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, u; cin >> n >> u;
    for (int i = 1; i <= n; ++i) cin >> e[i];
    int p = 1;
    long double ans = -inf;
    for (int i = 1; i <= n; ++i) {
        while (p <= n && e[p] - e[i] <= u) ++p;
        int q = p - 1;
        if (q - 1 > i) ans = max(ans, (e[q] - e[i + 1]) / (e[q] - e[i]));
    }
    if (ans < 0) cout << "-1" << endl;
    else cout << fixed << setprecision(20) << ans << endl;
}