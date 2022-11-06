#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn];
int n, m, k;
vector<int> v[maxn];

bool check(int t) {
    int d = maxn;
    for (int i = 1; i <= m; ++i) {
        if (v[i].size() < t) continue;
        for (int j = t - 1; j < v[i].size(); ++j) d = min(d, v[i][j] - v[i][j - t + 1] + 1 - t);
    }
    return d <= k;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) v[a[i]].push_back(i);
    int d = 30, ans = 0; 
    while (d--) if (ans + (1 << d) <= n) if (check(ans + (1 << d))) ans += (1 << d);
    cout << ans << endl;
    return 0;
}