#include <bits/stdc++.h>
#define int long long

using namespace std;

const int INF = 1e12 + 7;

/*int get_plus_xp(int k, int a, int b, int c, int d) {
    
}*/

int get_after_k(int k, int a, int b, int c, int d) {
    if (k == 0) return 0;
    int pl = a * k;
    int cnt_full = (k * d - c) / d;
    if (cnt_full < 0) cnt_full = 0;
    int mn = cnt_full * c;
    int rest = k - cnt_full - 1;
    mn += rest * (rest + 1) / 2 * d;
    return pl - mn * b;
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > b * c) {
        cout << "-1" << "\n";
        return;
    }
    int left = 0, right = INF, mid;
    while (right - left > 1) {
        mid = (left + right) / 2;
        if (get_after_k(mid, a, b, c, d) >= get_after_k(mid - 1, a, b, c, d)) left = mid;
        else right = mid;
    }
    //cout << left << endl;
    cout << get_after_k(left, a, b, c, d) << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}