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
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
        }
        string s(m, 'B');
        for (auto i : a) {
            if (s[min(i, m - i + 1) - 1] == 'A') {
                s[max(i, m - i + 1) - 1] = 'A';
            } else {
                s[min(i, m - i + 1) - 1] = 'A';
            }
        }
        cout << s << '\n';
    }
    return 0;
}