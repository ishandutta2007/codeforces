#include <bits/stdc++.h>
using namespace std;

const int maxn = 360;
int a[maxn];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 360;
    for (int l = 0; l <= n; ++l) {
        int st = 0, ed = l - 1;
        int now = 0;
        for (int i = st; i <= ed; ++i) now += a[i];
        ans = min(ans, abs((360 - now) - now));
        while (st < n) {
            now -= a[st];
            ++st; ed = (ed + 1) % n;
            now += a[ed];
            ans = min(ans, abs((360 - now) - now));
        }
    }
    cout << ans << endl;
    return 0;
}