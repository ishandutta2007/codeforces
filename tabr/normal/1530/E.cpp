#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        int n = (int) s.size();
        vector<int> z(26);
        for (int i = 0; i < n; i++) {
            z[s[i] - 'a']++;
        }
        int pp = -1;
        for (int i = 0; i < 26; i++) {
            if (z[i] == 1) {
                pp = i;
                break;
            }
        }
        if (pp != -1) {
            string res = string(z[pp], (char) ('a' + pp));
            for (int i = 0; i < 26; i++) {
                if (i != pp) {
                    res += string(z[i], (char) ('a' + i));
                }
            }
            cout << res << '\n';
            continue;
        }
        char c = *min_element(s.begin(), s.end());
        string x, y;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                y += s[i];
            } else {
                x += s[i];
            }
        }
        sort(x.begin(), x.end());
        int a = (int) y.size();
        int b = (int) x.size();
        s.clear();
        if (a <= b + 2) {
            for (int i = 0; i < (int) x.size(); i++) {
                if (i == 0) {
                    s += c;
                    a--;
                }
                if (a > 0) {
                    s += c;
                    a--;
                }
                s += x[i];
            }
            if (a > 0) {
                s += string(a, c);
            }
        } else if (b == 0) {
            s = y;
        } else {
            char d = x[0];
            int k = (int) (upper_bound(x.begin(), x.end(), d) - lower_bound(x.begin(), x.end(), d));
            if (k > 1) {
                if (k == b) {
                    k = 0;
                } else {
                    swap(x[k], x[1]);
                }
            }
            for (int i = 0; i < (int) x.size(); i++) {
                if (i == 0) {
                    s += c;
                    a--;
                }
                if (a > 0 && i == 1 && k > 1) {
                    s += string(a, c);
                    a = 0;
                }
                if (a > 0 && x[i] != d) {
                    s += string(a, c);
                    a = 0;
                }
                s += x[i];
            }
            if (a > 0) {
                s += string(a, c);
            }
        }
        cout << s << '\n';
    }
    return 0;
}