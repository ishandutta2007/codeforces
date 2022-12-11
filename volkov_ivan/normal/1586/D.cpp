#include <bits/stdc++.h>
//#define int long long

using namespace std;

int ask(int n, int all, int last) {
    int mn = min(all, last);
    all -= mn;
    last -= mn;
    all++;
    last++;
    cout << "?";
    for (int i = 0; i < n - 1; i++) {
        cout << ' ' << all;
    }
    cout << ' ' << last << endl;
    int x;
    cin >> x;
    return x;
}

signed main() {
    int n;
    cin >> n;
    int lst = 1;
    for (int i = 1; i < n; i++) {
        if (ask(n, 0, i) == 0) {
            lst = n + 1 - i;
            break;
        }
    }
    int res[n + 1];
    res[n] = lst;
    for (int i = 1; i <= n; i++) {
        if (i == lst)
            continue;
        int pos = ask(n, 0, i - lst);
        res[pos] = i;
    }
    cout << "!";
    for (int i = 1; i <= n; i++) {
        cout << ' ' << res[i];
    }
    cout << endl;
}