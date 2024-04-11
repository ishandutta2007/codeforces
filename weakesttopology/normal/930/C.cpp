#include <bits/stdc++.h>
using namespace std;
vector<int> LIS(const vector<int>& a) {
    int n = (int)size(a);
    vector<int> dp(n + 1, numeric_limits<int>::max()), hist(n);
    dp[0] = -1;
    for (int i = 0; i < n; ++i) {
        auto iter = upper_bound(begin(dp), end(dp), a[i]);
        *iter = a[i];
        hist[i] = int(iter - begin(dp));
    }
    return hist;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> c(m + 1);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        --l;
        ++c[l], --c[r];
    }
    c.pop_back();
    partial_sum(begin(c), end(c), begin(c));
    auto pref = LIS(c);
    reverse(begin(c), end(c));
    auto suff = LIS(c);
    reverse(begin(suff), end(suff));
    int k = 0;
    for (int j = 0; j < m; ++j) {
        int p = j ? pref[j - 1] : 0;
        int s = suff[j];
        k = max(k, p + s);
    }
    cout << k << '\n';
    exit(0);
}