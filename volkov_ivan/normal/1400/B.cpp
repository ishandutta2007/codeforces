#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int p, f, a, b, s, w;
    cin >> p >> f >> a >> b >> s >> w;
    if (s > w) {
        swap(a, b);
        swap(s, w);
    }
    int res = min(a, p / s + f / s);
    for (int i = 0; i <= a; i++) {
        if (i * s > p) continue;
        if ((a - i) * s > f) continue;
        int t1 = (p - i * s) / w;
        int t2 = (f - (a - i) * s) / w;
        res = max(res, a + min(b, t1 + t2));
    }
    cout << res << "\n";
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