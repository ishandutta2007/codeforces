#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    int lst = 0;
    cin >> lst;
    bool srtd = 1;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        if (x < lst) {
            srtd = 0;
        }
        lst = x;
    }
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) c1++;
        else c2++;
    }
    if (c1 != 0 && c2 != 0) {
        cout << "Yes" << endl;
        return;
    }
    if (srtd) {
        cout << "Yes" << endl;
        return;
    }
    cout << "No" << endl;
    return;
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int t; 
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}