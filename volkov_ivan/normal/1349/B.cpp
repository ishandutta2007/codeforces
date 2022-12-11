#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 3e5 + 7;
int f[N], a[N];
int pref1[N], pref2[N];
int n;

void upd(int pos, int val) {
    pos += n + 1;
    //cout << pos << ' ' << val << endl;
    for (int i = pos; i <= 2 * n + 10; i += i & (-i)) f[i] = min(f[i], val);
}

int get(int pos) {
    pos += n + 1;
    int res = N;
    for (int i = pos; i >= 1; i -= i & (-i)) res = min(res, f[i]);
    //cout << pos << ' ' << res << endl;
    return res;
}

void solve() {
    int k;
    cin >> n >> k;
    for (int i = 0; i <= 2 * n + 10; i++) f[i] = N;
    bool flag = 0;
    bool win = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == k) flag = 1;
        if (i != 1 && a[i] == k && a[i - 1] == k) {
            win = 1;
        }
    }
    if (n == 1 && a[1] == k) {
        cout << "yes\n";
        return;
    }
    if (!flag) {
        cout << "no\n";
        return;
    }
    if (win) {
        cout << "yes\n";
        return;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] >= k && a[i + 1] >= k) {
            cout << "yes\n";
            return;
        }
    }
    for (int i = 1; i <= n - 2; i++) {
        if (a[i] >= k && a[i + 2] >= k) {
            cout << "yes\n";
            return;
        }
    }
    cout << "no\n";
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 //   freopen("Desktop/input.txt", "r", stdin);
    int tt;
    cin >> tt;
    for (int i = 0; i < tt; i++) solve();
    return 0;
}