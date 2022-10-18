#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    vector<vector<int>> pos(x + 1);
    vector<int> prefmax(n);
    rep(i, 0, n) {
        cin >> a[i];
        pos[a[i]].push_back(i);
        prefmax[i] = max(a[i], (i != 0 ? prefmax[i - 1] : 0));
    }
    int p = 1, lst = n + 1;
    for (int i = x; i >= 1; i--) {
        if (pos[i].empty()) {
            p = i;
            continue;
        }
        if (pos[i].back() > lst)
            break;
        p = i;
        lst = pos[i][0];
    }
    ll ans = 0;
    lst = -1;
    for (int l = 1; l <= x; l++) {
        int r = max(l, p - 1);
        if (lst != -1)
            r = max(r, prefmax[lst]);
        ans += x - r + 1;
        if (!pos[l].empty()) {
            if (pos[l][0] < lst)
                break;
            lst = pos[l].back();
        }
    }
    cout << ans << endl;
    return 0;
}