#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, inf = 1e9 + 1;
int ans[maxn], a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> vec;
    for (int i = 1; i <= n; ++i) cin >> a[i], vec.emplace_back(a[i] + i, i);
    sort(vec.begin(), vec.end());
    for (size_t i = 0; i < vec.size(); ++i) {
        ans[i] = a[vec[i].second] + vec[i].second - 1 - i; 
    }
    int cur = inf;
    for (int i = n - 1; i >= 0; --i) {
        if (cur < ans[i]) return cout << ":(" << endl, 0;
        cur = min(cur, ans[i]);
    }
    for (int i = 0; i < n; ++i) cout << ans[i] << ' '; cout << endl;
    return 0;
}