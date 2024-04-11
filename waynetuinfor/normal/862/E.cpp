#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10, inf = 1e18;
int a[maxn], b[maxn];

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, q; cin >> n >> m >> q;
    long long s = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (i & 1) s += a[i];
        else s -= a[i];
    }
    for (int i = 1; i <= m; ++i) cin >> b[i];
    long long sb = 0;
    for (int i = 1; i <= n; ++i) {
        if (i & 1) sb += b[i];
        else sb -= b[i];
    }
    set<int> st;
    for (int j = 0; j <= m - n; ++j) {
        st.insert(sb);
        // cout << "j = " << j << " sb = " << sb << endl;
        int r = j + n + 1;
        // if (!(j & 1)) {
        sb -= b[j + 1]; sb *= -1;
        if (r % 2  == j % 2) sb += b[r];
        else sb -= b[r];
    }
    auto it = st.lower_bound(s);
    int ans = inf;
    if (it != st.end()) ans = abs(*it - s);
    for (int i = 0; i < 5; ++i) {
        --it;
        ans = min(ans, abs(*it - s));
        if (it == st.begin()) break;
    }
    // for (auto itt = st.begin(); itt != st.end(); ++itt) cout << *itt << ' '; cout<< endl;
    cout << ans << endl;
    while (q--) {
        int l, r, x; cin >> l >> r >> x;
        if ((r - l + 1) & 1) {
            if (l & 1) s += x;
            else s -= x;
        }
        // cout << "s = " << s << endl;
        auto it = st.lower_bound(s);
        int ans = inf;
        if (it != st.end()) ans = abs(*it - s);
        for (int i = 0; i < 5; ++i) {
            --it;
            ans = min(ans, abs(*it - s));
            if (it == st.begin()) break;
        }
        cout << ans << endl;
    }
    return 0;
}