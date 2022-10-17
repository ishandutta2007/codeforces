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
        string s;
        cin >> s;
        bool ok = false;
        for (int i = 0; i < SZ(s); i++) {
            if ((i == 0 || s[i - 1] != s[i]) && (i + 1 == SZ(s) || s[i + 1] != s[i])) {
                ok = true;
            }
        }
        if (ok) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}