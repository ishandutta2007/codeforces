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
        int n;
        cin >> n;
        n *= 2;
        string s;
        cin >> s;
        vector<int> a(n + 1);
        for (int i = 0; i < n; i++) {
            a[i + 1] = a[i] + (s[i] == '(' ? 1 : -1);
        }
        if (*min_element(a.begin(), a.end()) >= 0) {
            cout << 0 << '\n';
            continue;
        }
        int p1 = (int) (find(a.begin(), a.end(), -1) - a.begin());
        int p2 = (int) (a.rend() - find(a.rbegin(), a.rend(), -1) - 1);
        int r = (int) (max_element(a.begin() + p2, a.end()) - a.begin());
        int l = (int) (a.rend() - max_element(a.rbegin() + n - p1, a.rend()) - 1);
        string t = s;
        reverse(t.begin() + l, t.begin() + r);
        vector<int> b(n + 1);
        for (int i = 0; i < n; i++) {
            b[i + 1] = b[i] + (t[i] == '(' ? 1 : -1);
        }
        if (*min_element(b.begin(), b.end()) >= 0) {
            cout << 1 << '\n';
            cout << l + 1 << " " << r << '\n';
            continue;
        }
        int p = (int) (max_element(a.begin(), a.end()) - a.begin());
        cout << 2 << '\n';
        cout << 1 << " " << p << '\n';
        cout << p + 1 << " " << n << '\n';
    }
    return 0;
}