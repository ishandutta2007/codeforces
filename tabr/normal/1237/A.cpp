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
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = a[i] / 2;
    }
    int c = accumulate(b.begin(), b.end(), 0);
    for (int i = 0; i < n; i++) {
        if (c != 0 && a[i] % 2) {
            if (c > 0 && a[i] < 0) {
                b[i]--;
                c--;
            }
            if (c < 0 && a[i] > 0) {
                b[i]++;
                c++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << b[i] << '\n';
    }
    return 0;
}