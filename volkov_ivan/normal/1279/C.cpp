#include <iostream>
#define int long long

using namespace std;

const int N = 1e5 + 7;
int a[N], obr[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        obr[a[i]] = i;
    }
    int ans = 0;
    int maxi = -1;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        x = obr[x];
        if (maxi > x) {
            ans++;
            continue;
        }
        ans += 2 * (x - i) + 1;
        maxi = x;
    }
    cout << ans << "\n";
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}