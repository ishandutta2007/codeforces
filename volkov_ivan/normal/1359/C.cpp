#include <bits/stdc++.h>
#define int long long

using namespace std;

const int INF = 1e12;
const long double one = 1.0;

long double calc(int c, int h, int mid) {
    int kek = mid * h + (mid - 1) * c;
    long double res = (one * kek) / (2 * mid - 1);
    return res;
}

void solve() {
    int c, h, t;
    cin >> h >> c >> t;
    if (t >= h) {
        cout << 1 << endl;
        return;
    }
    if (t <= (c + h) / 2) {
        cout << 2 << endl;
        return;
    }
    int l = 0, r = INF, mid;
    while (r - l > 1) {
        mid = (l + r) / 2;
        if (calc(c, h, mid) >= t) l = mid;
        else r = mid;
    }
    long double val1 = calc(c, h, l), val2 = calc(c, h, l + 1);
    long double d1 = fabs(t - val1), d2 = fabs(t - val2);
    if (d1 <= d2) {
        cout << 2 * l - 1 << endl;
    } else {
        cout << 2 * l + 1 << endl;
    }
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}