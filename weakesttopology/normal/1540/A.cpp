#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> d(n);
        for (int u = 0; u < n; ++u) {
            cin >> d[u];
        }
        sort(begin(d) + 1, end(d));
        vector<ll> suffsum(n);
        partial_sum(rbegin(d), rend(d), rbegin(suffsum));
        ll ans = d.back();
        for (int u = 0; u < n - 1; ++u) {
            ans += (n - u - 1) * d[u] - suffsum[u + 1];
        }
        cout << ans << endl;
    }
    exit(0);
}