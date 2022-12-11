#include <bits/stdc++.h>
//#define int long long

using namespace std;

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    int a[n];
    int cnt_1 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1)
            cnt_1++;
    }
    for (int i = 0; i < q; i++) {
        int t, k;
        cin >> t >> k;
        if (t == 1) {
            k--;
            a[k] = 1 - a[k];
            if (a[k] == 1)
                cnt_1++;
            else
                cnt_1--;
        } else {
            if (cnt_1 >= k)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
    }
    return 0;
}