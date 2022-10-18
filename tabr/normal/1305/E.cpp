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
    if (m > (n - 1) * (n - 1) / 4) {
        cout << -1 << '\n';
        return 0;
    }
    vector<int> a(n);
    a[0] = 1, a[1] = 2;
    int cur = 0;
    int k = 0;
    if (m == 0) {
        k = 3;
    }
    for (int i = 2; i < n; i++) {
        if (cur == m) {
            a[i] = a[i - 1] + k;
        } else if (cur + i / 2 <= m) {
            a[i] = i + 1;
            cur += i / 2;
            k = a[i] + 1;
        } else {
            int p = m - cur;
            a[i] = 2 * i - 2 * p + 1;
            cur = m;
            k = a[i] + 1;
        }
    }
    for (int i : a) {
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}