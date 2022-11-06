#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e3 + 10;
int a[maxn];

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (k * 2LL >= a[i]) k = max(k, a[i]);
        else {
            while (k * 2LL < a[i]) ++ans, k *= 2LL;
            k = max(k, a[i]);
        }
    } 
    cout << ans << endl;
    return 0;
}