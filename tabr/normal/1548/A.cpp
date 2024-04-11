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
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (a > b) {
            swap(a, b);
        }
        x[a]++;
    }
    int ans = n;
    for (int i = 0; i < n; i++) {
        if (x[i]) {
            ans--;
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int c;
        cin >> c;
        if (c == 1) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            if (a > b) {
                swap(a, b);
            }
            x[a]++;
            if (x[a] == 1) {
                ans--;
            }
        } else if (c == 2) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            if (a > b) {
                swap(a, b);
            }
            x[a]--;
            if (x[a] == 0) {
                ans++;
            }
        } else {
            cout << ans << '\n';
        }
    }
    return 0;
}