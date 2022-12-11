#include <bits/stdc++.h>

using namespace std;

void solve() {
    int v, u;
    cin >> v >> u;
    if (v > u) {
        cout << "NO\n";
        return;
    }
    int a = __builtin_popcount(v), b = __builtin_popcount(u);
    if (b > a) {
        cout << "NO\n";
        return;
    }
    vector <int> lft, rght;
    for (int pos = 31; pos >= 0; pos--) {
        int v_bit = ((1 << pos) & v) >> pos;
        int u_bit = ((1 << pos) & u) >> pos;
        if (v_bit == 0 && u_bit == 1) {
            int diff = a - b + 1;
            for (int j = pos - 1; j >= 0; j--) {
                if ((1 << j) & v) {
                    if (diff > 0) {
                        diff--;
                    } else {
                        lft.push_back(j);
                    }
                }
                if ((1 << j) & u) {
                    rght.push_back(j);
                }
            }
            break;
        }
    }
    assert(lft.size() == rght.size());
    for (int i = 0; i < (int) lft.size(); i++) {
        if (lft[i] > rght[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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