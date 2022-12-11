#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 7;
int perm[N], wh[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> perm[i];
        wh[perm[i]] = i;
    }
    int lst = n;
    int cur = 1;
    while (lst != 0) {
        int pos = wh[cur];
        if (pos > lst) {
            cout << "No\n";
            return;
        }
        for (int i = pos; i <= lst; i++) {
            if (perm[i] != cur) {
                cout << "No\n";
                return;
            }
            cur++;
        }
        lst = pos - 1;
    }
    cout << "Yes\n";
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}