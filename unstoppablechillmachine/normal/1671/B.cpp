#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

signed main() {
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &it : a) {
            cin >> it;
        }
        sort(all(a));
        bool ok = false;
        for (int l : {a[0] - 1, a[0], a[0] + 1}) {
            bool cur = true;
            for (int i = 0; i < n; i++) {
                if (abs(a[i] - l - i) > 1) {
                    cur = false;
                }
            }
            if (cur) {
                ok = true;
            }
        }
        if (ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}