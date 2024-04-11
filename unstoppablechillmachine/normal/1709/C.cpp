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
        int balance = 0, q = 0;
        bool ok = true;
        for (auto it : s) {
            if (it == '?') {
                q++;
            } else if (it == '(') {
                balance++;
            } else {
                balance--;
            }
        }
        if (abs(balance) > q || (abs(balance) + q) % 2 == 1) {
            cout << "NO\n";
            continue;
        }
        string s2 = s;
        int r = -1, l = -1, pos = 0;
        for (auto &it : s2) {
            if (it == '?') {
                if (abs(balance + 1) <= q - 1) {
                    it = '(';
                    r = pos;
                    balance++;
                    q--;
                } else {
                    it = ')';
                    if (l == -1) {
                        l = pos;
                    }
                    balance--;
                    q--;
                }
            }
            pos++;
        }
        if (l == -1 || r == -1) {
            cout << "YES\n";
            continue;
        }
        swap(s2[l], s2[r]);
        balance = 0;
        ok = true;
        for (auto it : s2) {
            if (it == '(') {
                balance++;
            } else {
                balance--;
                if (balance < 0) {
                    ok = false;
                }
            }
        }
        if (!ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}