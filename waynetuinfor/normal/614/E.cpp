#include <bits/stdc++.h>
using namespace std;

int c[26];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int od = -1;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        if (c[i] & 1) {
            if (od != -1) ok = false;
            else od = i;
        }
    }
    if (!ok) {
        cout << "0" << endl;
        for (int i = 0; i < n; ++i) {
            while (c[i]--) cout << (char)(i + 'a');
        }
        cout << endl;
        return 0;
    }
    int g = 0;
    for (int i = 0; i < n; ++i) g = __gcd(c[i], g);
    int ans = 0;
    bool odd = false;
    for (int d = 1; d <= g; ++d) if (g % d == 0) {
        int od = -1;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if ((c[i] / d) & 1) {
                if (od != -1) ok = false;
                else od = i;
            }
        }
        if (!ok) continue;
        if (od == -1) {
            if (d * 2 > ans) ans = d * 2, odd = false;
        } else {
            if (d > ans) ans = d, odd = true;
        }
    }
    cout << ans << endl;
    if (!odd) ans /= 2;
    for (int j = 0; j < ans; ++j) {
        int od = -1;
        for (int i = 0; i < n; ++i) {
            if ((c[i] / ans) & 1) od = i;
        }
        for (int i = 0; i < n; ++i) if (od != i) {
            for (int k = 0; k < (c[i] / ans) / 2; ++k) cout << (char)(i + 'a');
        }
        if (od != -1) {
            for (int k = 0; k < c[od] / ans; ++k) cout << (char)(od + 'a');
        }
        for (int i = n - 1; i >= 0; --i) if (od != i) {
            for (int k = 0; k < (c[i] / ans) / 2; ++k) cout << (char)(i + 'a');
        }
    }
    cout << endl;
    return 0;
}