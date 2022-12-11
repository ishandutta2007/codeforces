#include <bits/stdc++.h>
#define int long long

using namespace std;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    bool flag = 1;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        bool ok = 0;
        for (int j = i; j >= i - 20 && j >= 1; j--) {
            if (x % (j + 1) != 0) {
                ok = 1;
                break;
            }
        }
        flag &= ok;
    }
    cout << (flag ? "YES" : "NO") << "\n";
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