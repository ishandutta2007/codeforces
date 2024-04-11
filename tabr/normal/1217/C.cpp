#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        int lst = -1, ans = 0;
        rep(i, 0, s.size()) {
            if (s[i] == '0')
                continue;
            int x = 0;
            rep(j, i, s.size()) {
                x = 2 * x + (s[j] - '0');
                if (j - x < lst)
                    break;
                ans++;
            }
            lst = i;
        }
        cout << ans << endl;
    }

    return 0;
}