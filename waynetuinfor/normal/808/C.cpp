#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
int a[maxn], ans[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, w; cin >> n >> w;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<pair<int, int>> vec;
    for (int i = 1; i <= n; ++i) vec.push_back(make_pair(a[i], i));
    sort(vec.begin(), vec.end()); reverse(vec.begin(), vec.end());
    for (auto i : vec) {
        ans[i.second] = (i.first & 1 ? i.first / 2 + 1 : i.first / 2);
        w -= (i.first & 1 ? i.first / 2 + 1 : i.first / 2);
        if (w < 0) return cout << "-1\n", 0;
    }
    for (auto i : vec) {
        int add = min(a[i.second] - ans[i.second], w);
        ans[i.second] += add;
        w -= add;
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' '; cout << endl;
    return 0;
    // int ans = bs()
}