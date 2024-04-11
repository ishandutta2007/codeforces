#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 7;
int pref[N], suff[N], a[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    pref[1] = 0;
    for (int i = 1; i <= n; i++) {
        if (pref[i] < 0) {
            pref[i + 1] = -1;
            continue;
        }
        pref[i + 1] = a[i] - pref[i];
    }
    suff[n] = 0;
    for (int i = n; i >= 1; i--) {
        if (suff[i] < 0) {
            suff[i - 1] = -1;
            continue;
        }
        suff[i - 1] = a[i] - suff[i];
    }
    if (pref[n + 1] == 0) {
        cout << "YES\n";
        return;
    }
    for (int i = 1; i < n; i++) {
        int j = i + 1;
        if (pref[i] < 0 || suff[j] < 0)
            continue;
        int lft = a[j] - pref[i];
        int rght = a[i] - suff[j];
        if (lft == rght && lft >= 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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