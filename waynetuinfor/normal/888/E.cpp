#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 35;
int a[maxn];

int32_t main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int h = n / 2;
    set<int> st;
    for (int s = 0; s < (1 << h); ++s) {
        int t = 0;
        for (int i = 0; i < h; ++i) if ((1 << i) & s) {
            t += a[i];
            t %= m;
        }
        st.insert(t);
    }
    int ans = 0;
    for (int s = 0; s < (1 << (n - h)); ++s) {
        int t = 0;
        for (int i = 0; i < n - h; ++i) if ((1 << i) & s) {
            t += a[i + h];
            t %= m;
        }
        int to = m - 1 - t; to += m; to %= m;
        auto it = --(st.upper_bound(to));
        ans = max(ans, (*it + t) % m);
    }
    cout << ans << endl;
    return 0;
}