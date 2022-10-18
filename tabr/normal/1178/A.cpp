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
    vector<int> b;
    b.emplace_back(1);
    int s = a[0];
    for (int i = 1; i < n; i++) {
        if (a[0] >= a[i] * 2) {
            b.emplace_back(i + 1);
            s += a[i];
        }
    }
    if (s * 2 <= accumulate(a.begin(), a.end(), 0)) {
        cout << 0 << '\n';
        return 0;
    }
    cout << b.size() << '\n';
    for (int i : b) {
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}