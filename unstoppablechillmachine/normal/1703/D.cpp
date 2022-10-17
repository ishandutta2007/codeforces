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
        int n;
        cin >> n;
        vector<string> s(n);
        set<string> have;
        for (auto &t : s) {
            cin >> t;
            have.insert(t);
        }
        for (int i = 0; i < n; i++) {
            bool ok = false;
            for (int j = 0; j + 1 < s[i].size(); j++) {
                if (have.count(s[i].substr(0, j + 1)) && have.count(s[i].substr(j + 1, static_cast<int>(s[i].size()) - j - 1))) {
                    ok = true;
                    break;
                }
            }
            cout << (ok ? 1 : 0);
        }
        cout << '\n';
    }
    return 0;
}