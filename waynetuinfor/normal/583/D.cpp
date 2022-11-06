#include <bits/stdc++.h>
using namespace std;

const int maxn = 300 + 10;
int a[maxn], c[maxn], dp[maxn * maxn];

int main() {
    int n, t; cin >> n >> t;
    for (int i = 1; i <= n; ++i) cin >> a[i], ++c[a[i]];
    vector<int> v;
    for (int i = 0; i < min(n, t); ++i) {
        for (int j = 1; j <= n; ++j) v.push_back(a[j]);
    }
    // for (int i : v) cout << i << ' '; cout << endl;
    for (int i = 0; i < v.size(); ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) if (v[i] >= v[j]) dp[i] = max(dp[i], dp[j] + 1);
    }
    int cc = *max_element(c, c + maxn);
    cout << *max_element(dp, dp + maxn * maxn) + max(0, t - n) * cc << endl;
}