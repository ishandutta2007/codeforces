#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        ll ans = 0;
        for(int i = 0; i < n; ++i) cin >> a[i], ans += a[i] / m, a[i] %= m;
        sort(a.begin(), a.end());
        for(int i = n - 1, j = 0; i > j; --i) {
            while(j < i && a[i] + a[j] < m) ++j;
            if(j >= i) break;
            ++j, ++ans;
        }
        cout << ans << '\n';
    }
}