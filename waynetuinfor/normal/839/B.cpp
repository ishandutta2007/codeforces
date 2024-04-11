#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    int c = n, d = n * 2, e = 0;
    for (int i = 0; i < k; ++i) cin >> a[i];
    for (int i = 0; i < k; ++i) {
        int o = min(c, a[i] / 4);
        c -= o; a[i] -= 4 * o;
    }
    for (int i = 0; i < k; ++i) {
        int o = min(d / 2, a[i] / 4);
        d -= 2 * o; a[i] -= 4 * o;
    }
    for (int i = 0; i < k; ++i) {
        int o = min(c, a[i] / 3);
        c -= o; a[i] -= 3 * o;
    }
    for (int i = 0; i < k; ++i) {
        int o = min(d / 2, a[i] / 3);
        d -= 2 * o; a[i] -= 3 * o;
    }
    for (int i = 0; i < k; ++i) {
        int o = min(c, a[i] / 2);
        c -= o; a[i] -= 2 * o;
        e += o;
    }
    for (int i = 0; i < k; ++i) {
        int o = min(d, a[i] / 2);
        d -= o; a[i] -= 2 * o;
    }
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        ans += a[i];
    }
    ans -= c * 2;
    ans -= d; ans -= e;
    if (ans > 0) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}