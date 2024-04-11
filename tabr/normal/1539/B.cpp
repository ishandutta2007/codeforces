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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - 'a' + 1;
    }
    vector<int> b(n + 1);
    for (int i = 0; i < n; i++) {
        b[i + 1] = b[i] + a[i];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << b[r] - b[l - 1] << '\n';
    }
    return 0;
}