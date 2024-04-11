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
        if (s.size() == 2) {
            cout << s[1] << '\n';
        } else {
            cout << *min_element(s.begin(), s.end()) << '\n';
        }
    }
    return 0;
}