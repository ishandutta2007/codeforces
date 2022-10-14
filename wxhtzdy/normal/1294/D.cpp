#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q, x;
    cin >> q >> x;
    int ans = 0;
    vector<int> cnt(x, 0);
    while (q--) {
        int a;
        cin >> a;
        cnt[a % x]++;
        while (cnt[ans % x] > 0) cnt[ans % x]--, ans++;
        cout << ans << '\n';
    }
    return 0;
}