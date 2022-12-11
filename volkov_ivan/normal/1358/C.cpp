#include <bits/stdc++.h>
#define int long long

using namespace std;

int calc(int a, int b) {
    if (a > b) swap(a, b);
    //cout << a << ' ' << b << endl;
    int r = a - 1;
    int res = r * (r + 1);
    res += r * (a + b - 1 - 2 * a);
    return res;
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int p = 0; p < t; p++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int a = x2 - x1 + 1;
        int b = y2 - y1 + 1;
        cout << calc(a, b) + 1 << endl;
    }
}