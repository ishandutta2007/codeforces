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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m = 500;
    vector<int> c(1 << (32 - __builtin_clz(m)), m + 10);
    c[0] = 0;
    for (int i = 0; i < n; i++) {
        vector<int> new_c = c;
        for (int j = 0; j < (int) c.size(); j++) {
            if (c[j] < a[i]) {
                new_c[j ^ a[i]] = min(new_c[j ^ a[i]], a[i]);
            }
        }
        swap(c, new_c);
    }
    cout << count_if(c.begin(), c.end(), [&](int i) { return i <= m; }) << '\n';
    for (int i = 0; i < (int) c.size(); i++) {
        if (c[i] <= m) {
            cout << i << " ";
        }
    }
    cout << '\n';
    return 0;
}