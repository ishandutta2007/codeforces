#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    map <pair <int, int>, int> cnt2;
    map <int, int> cnt;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int w, h;
        cin >> w >> h;
        if (w > h)
            swap(w, h);
        if (w != h)
            cnt2[{w, h}]++;
        cnt[w]++;
        if (w != h)
            cnt[h]++;
    }
    int ans = 0;
    for (auto elem : cnt) {
        ans += elem.second * (elem.second - 1) / 2;
    }
    for (auto elem : cnt2) {
        ans -= elem.second * (elem.second - 1) / 2;
    }
    cout << ans << "\n";
}