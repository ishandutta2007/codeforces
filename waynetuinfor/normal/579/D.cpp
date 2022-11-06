#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
const long long inf = 1e18;
long long a[maxn], k, x, n, pre[maxn], suf[maxn];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k >> x;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] | a[i];
    for (int i = n; i > 0; --i) suf[i] = suf[i + 1] | a[i];
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        long long now = a[i];
        for (int j = 0; j < k; ++j) now *= x;
        ans = max(ans, pre[i - 1] | now | suf[i + 1]);
    } 
    cout << ans << endl;
    return 0;
}