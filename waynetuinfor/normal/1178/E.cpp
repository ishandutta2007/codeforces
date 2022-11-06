#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    string s; cin >> s;
    int n = (int)s.size();
    int i = 0, j = n - 2;
    string x = "", y = "";
    for (; i + 1 < j; i += 2, j -= 2) {
        int p = -1, q = -1;
        for (int a = 0; a < 2 && p == -1; ++a) {
            for (int b = 0; b < 2; ++b) {
                if (s[i + a] == s[j + b]) {
                    p = a;
                    q = b;
                    break;
                }
            }
        }
        assert(p != -1);
        x += s[i + p];
        y += s[i + p];
    }

    if (n % 4 != 0) {
        x += s[i];
    }

    string ans = x;
    reverse(y.begin(), y.end());
    ans += y;
    assert((int)ans.size() >= (int)s.size() / 2);
    cout << ans << endl;
    return 0;
}