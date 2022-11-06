#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, inf = 1e9 + 1;
int s[maxn], g[maxn], lb[maxn], ub[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> s[i] >> g[i];
    for (int i = 1; i <= n; ++i) lb[i] = s[i], ub[i] = s[i] + g[i];
    int lbnow = -inf, ubnow = inf;
    for (int i = 1; i <= n; ++i) {
        --lbnow; ++ubnow;
        lbnow = max(lbnow, lb[i]);
        ubnow = min(ubnow, ub[i]);
        ub[i] = ubnow;
        lb[i] = lbnow;
        if (lbnow > ubnow) return cout << "-1" << endl, 0;
    }
    for (int i = n - 1; i >= 1; --i) {
        --lbnow; ++ubnow;
        lbnow = max(lbnow, lb[i]);
        ubnow = min(ubnow, ub[i]);
        ub[i] = ubnow;
        lb[i] = lbnow;
        if (lbnow > ubnow) return cout << "-1" << endl, 0;
    }
    long long ans = 0ll;
    for (int i = 1; i <= n; ++i) ans += ub[i] - s[i];
    cout << ans << endl;
    for (int i = 1; i <= n; ++i) cout << ub[i] << ' '; cout << endl;
}