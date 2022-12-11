#include <iostream>

using namespace std;

void del(string &s, int pos) {
    string t = "";
    for (int i = 0; i < pos; i++) t += s[i];
    for (int i = pos + 1; i < (int) s.length(); i++) t += s[i];
    s = t;
}

signed main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (char x = 'z'; x >= 'b'; x--) {
        char prv = x - 1;
        bool flag = 1;
        while (flag) {
            flag = 0;
            for (int i = 0; i < (int) s.length(); i++) {
                if (s[i] != x) continue;
                if (i > 0 && s[i - 1] == prv) {
                    del(s, i);
                    flag = 1;
                    ans++;
                    break;
                }
                if (i != (int) s.length() - 1 && s[i + 1] == prv) {
                    del(s, i);
                    flag = 1;
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}