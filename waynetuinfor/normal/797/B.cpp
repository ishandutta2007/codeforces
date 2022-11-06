#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    int ans = 0;
    vector<int> odd;
    for (int i : v) {
        if (i & 1) odd.push_back(i);
        else if (i > 0) ans += i;
    }
    reverse(odd.begin(), odd.end());
    int Max = INT_MIN, cur = 0, cnt = 0;
    for (int i : odd) {
        cur += i;
        ++cnt;
        if (cnt & 1) Max = max(Max, cur);
    }
    cout << ans + Max << '\n';
    return 0;
}