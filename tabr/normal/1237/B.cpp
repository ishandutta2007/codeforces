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
    vector<int> a(n), b(n);
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        c[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
        b[i] = c[b[i]];
        a[b[i]] = i;
    }
    int ans = 0;
    int lst = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] < lst) {
            ans++;
        } else {
            lst = a[i];
        }
    }
    cout << ans << '\n';
    return 0;
}