#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int h[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    h[0] = 0;
    for (int i = 1; i <= n; ++i) cin >> h[i];
    int cur = 0, ans = 0;
    for (int i = 1; i <= n; ++i) {
        cur += h[i - 1] - h[i];
        if (cur < 0) ans -= cur, cur = 0;
    }
    cout << ans << '\n';
    return 0;
}