#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10, inf = 1e9 + 1;

int bs(int a, int x) {
    int d = 30, ans = inf;
    while (d--) if (ans - (1 << d) >= 0) if (x * (ans - (1 << d)) >= a) ans -= (1 << d);
    return ans * x;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, x, k; cin >> n >> x >> k;
    vector<int> a(n), xs;
    for (int i = 0; i < n; ++i) cin >> a[i];
    // for (int i = 0; x * i < inf; ++i) xs.push_back(x * i);
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int lb = bs(a[i], x);
        int ub = lb + k * x;
        lb = ub - x;
        lb = max(lb, a[i]); ub = max(ub, a[i]);
        // cout << "lb = " << lb << " ub = " << ub << endl;
        ans += lower_bound(a.begin(), a.end(), ub) - lower_bound(a.begin(), a.end(), lb);
    }
    cout << ans << endl;
    return 0;
}