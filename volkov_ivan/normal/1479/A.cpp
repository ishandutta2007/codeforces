#include <bits/stdc++.h>
//#define int long long

using namespace std;

int n;

int ask(int x) {
    int l = n + 2, r = n + 2, mid;
    cout << "? " << x << endl;
    cin >> mid;
    if (x != 1) {
        cout << "? " << x - 1 << endl;
        cin >> l;
    }
    if (x != n) {
        cout << "? " << x + 1 << endl;
        cin >> r;
    }
    if (mid < l && mid < r) {
        cout << "! " << x << endl;
        exit(0);
    }
    if (mid > l)
        return -1;
    return 1;
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ask(1);
    ask(n);
    int l = 1, r = n, mid;
    while (r - l > 1) {
        mid = (l + r) / 2;
        int val = ask(mid);
        if (val == -1)
            r = mid;
        else
            l = mid;
    }
    return -1;
}