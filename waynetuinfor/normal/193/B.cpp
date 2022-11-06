#include <bits/stdc++.h>
using namespace std;

const int maxn = 30 + 5;
const long long inf = 1e18;
int a[maxn], p[maxn], b[maxn], k[maxn], u, r, n;
long long ans;

void dfs(vector<int> a, int now, bool x) {
    int left = u - now;
    if (left % 2 == 0) {
        long long s = 0;
        for (int i = 1; i <= n; ++i) s += a[i] * 1ll * k[i];
        ans = max(ans, s);
    }
    if (now == u) return;
    vector<int> na(a.begin(), a.end());
    for (int i = 1; i <= n; ++i) na[i] = a[p[i]] + r;
    dfs(na, now + 1, false);
    if (x) return;
    na = vector<int>(a.begin(), a.end());
    for (int i = 1; i <= n; ++i) na[i] = (a[i] ^ b[i]);
    dfs(na, now + 1, true);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> u >> r;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i) cin >> k[i];
    for (int i = 1; i <= n; ++i) cin >> p[i];
    ans = -inf;
    dfs(vector<int>(a, a + maxn), 0, false);
    cout << ans << endl;
    return 0;
}