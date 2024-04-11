#include <bits/stdc++.h>
//#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    map <int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[abs(x)]++;
    }
    int res = 0;
    for (auto elem : cnt) {
        res++;
        if (elem.second > 1 && elem.first != 0)
            res++;
    }
    cout << res << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) 
        solve();
    return 0;
}