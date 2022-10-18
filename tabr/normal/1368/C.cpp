#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    cout << 3 * n + 4 << '\n';
    for (int i = 0; i < n + 2; i++) {
        for (int j = max(i - 1, 0); j <= min(i + 1, n + 1); j++) {
            cout << i << " " << j << '\n';
        }
    }
    return 0;
}