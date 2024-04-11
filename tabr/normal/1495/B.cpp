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
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    vector<int> l(n), r(n);
    for (int i = 1; i < n; i++) {
        if (p[i - 1] < p[i]) {
            l[i] = l[i - 1] + 1;
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (p[i + 1] < p[i]) {
            r[i] = r[i + 1] + 1;
        }
    }
    int mx = max(*max_element(l.begin(), l.end()), *max_element(r.begin(), r.end()));
    int t = -1;
    for (int i = 0; i < n; i++) {
        if (l[i] == mx || r[i] == mx) {
            if (t != -1) {
                cout << 0 << '\n';
                return 0;
            }
            t = i;
        }
    }
    if (t == 0 || t == n - 1 || mx % 2 == 1) {
        cout << 0 << '\n';
    } else if (l[t] == mx && r[t] == mx) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
    return 0;
}