#include <bits/stdc++.h>

using namespace std;

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int res = 0; res < 512; res++) {
        bool poss = 1;
        for (int i = 0; i < n; i++) {
            bool flag = 0;
            for (int j = 0; j < m; j++) {
                int c = a[i] & b[j];
                if ((c | res) == res) {
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                poss = 0;
                break;
            }
        }
        if (poss) {
            cout << res << endl;
            return 0;
        }
    }
    return -1;
}