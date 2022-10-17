#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        if (s.size() != 3) {
            cout << "NO\n";
            continue;
        }
        if ((s[0] != 'y' && s[0] != 'Y') || (s[1] != 'e' && s[1] != 'E') || (s[2] != 's' && s[2] != 'S')) {
            cout << "NO\n";
        } else {
            cout << "YES\n";        
        }
    }
    return 0;
}