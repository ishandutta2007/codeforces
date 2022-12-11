#include <bits/stdc++.h>

using namespace std;

int k;
int a[8];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        cin >> k;
        int nday = 0;
        for (int i = 0; i < 7; ++i) cin >> a[i], nday += a[i];
        int whole_weeks = (k - 1) / nday;
        k = (k - 1) % nday;
        int ans = 1e9;
        for (int i = 0; i < 7; ++i) if (a[i]) {
            int opt = 1 + 7 * whole_weeks;
            int need = k, cur = i;
            while (need) cur = (cur + 1) % 7, need -= a[cur], ++opt;
            ans = min(ans, opt);
        }
        cout << ans << '\n';
    }
    return 0;
}