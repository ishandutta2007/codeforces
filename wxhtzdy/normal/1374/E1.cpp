#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> v[4];
    for (int i = 0; i < n; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        v[a * 2 + b].push_back(t);
    }
    vector<long long> pref[4];
    for (int i = 0; i < 4; i++) {
        sort(v[i].begin(), v[i].end());
        pref[i].push_back(0);
        for (int h : v[i]) {
            pref[i].push_back(pref[i].back() + h);
        }
    }
    const long long inf = 1e18;
    long long ans = inf;
    for (int i = 0; i < min(k + 1, int(v[3].size()) + 1); i++) {
        int cnt_a = k - i, cnt_b = k - i;
        if (k - i < int(pref[1].size()) && k - i < int(pref[2].size())) {
            ans = min(ans, pref[3][i] + pref[1][k - i] + pref[2][k - i]);
        }
    }
    if (ans == inf) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
    return 0;
}