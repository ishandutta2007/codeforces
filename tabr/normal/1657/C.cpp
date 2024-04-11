#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

vector<int> manacher(const string &s) {
    int n = (int) s.size();
    vector<int> res(2 * n - 1);
    int l = -1, r = -1;
    for (int k = 0; k < 2 * n - 1; k++) {
        int i = (k + 1) >> 1;
        int j = k >> 1;
        int p = (r <= i ? 0 : min(r - i, res[2 * (l + r) - k]));
        while (0 <= i - p - 1 && j + p + 1 < n && s[i - p - 1] == s[j + p + 1]) {
            p++;
        }
        if (r < j + p) {
            l = i - p;
            r = j + p;
        }
        res[k] = p;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        auto z = manacher(s);
        int c = 0, r = n;
        for (int i = 0; i < n - 1;) {
            debug(c, r);
            if (s[i] == '(') {
                r -= 2;
                c += 1;
                i += 2;
                continue;
            }
            int k = -1;
            for (int j = i + 1; j < n; j++) {
                if (z[i + j] * 2 + ((j - i) % 2 == 0) >= j - i + 1) {
                    k = j - i + 1;
                    break;
                }
            }
            if (k == -1) {
                break;
            }
            r -= k;
            c += 1;
            i += k;
        }
        cout << c << " " << r << '\n';
    }
    return 0;
}