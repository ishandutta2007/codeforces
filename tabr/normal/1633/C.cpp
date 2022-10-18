#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        long long hc, dc;
        cin >> hc >> dc;
        long long hm, dm;
        cin >> hm >> dm;
        int k;
        long long w, a;
        cin >> k >> w >> a;
        string ans = "NO";
        for (int i = 0; i <= k; i++) {
            long long h = hc + i * a;
            long long d = dc + (k - i) * w;
            long long me = (h + dm - 1) / dm;
            long long his = (hm + d - 1) / d;
            if (me >= his) {
                ans = "YES";
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}