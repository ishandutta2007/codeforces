#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn], req[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int h = 0;
    req[n] = a[n] + 1;
    for (int i = n - 1; i > 0; --i) req[i] = max(req[i + 1] - 1, a[i] + 1);
    for (int i = 1; i <= n; ++i) req[i] = max(req[i - 1], req[i]);
    long long ans = 0;
    for (int i = 1; i <= n; ++i) ans += req[i] - a[i] - 1;
    cout << ans << endl;
    return 0;
}