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
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long g = 0;
    for (int i = 0; i < n - 1; i++) {
        g = __gcd(g, a[i + 1] - a[i]);
    }
    for (int j = 0; j < m; j++) {
        long long b;
        cin >> b;
        cout << __gcd(g, a[0] + b) << '\n';
    }
    return 0;
}