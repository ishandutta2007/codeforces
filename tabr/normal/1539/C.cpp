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
    long long k, x;
    cin >> n >> k >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<long long> b;
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] - a[i] > x) {
            b.emplace_back(a[i + 1] - a[i]);
        }
    }
    sort(b.begin(), b.end());
    int ans = 1 + (int) b.size();
    for (int i = 0; i < (int) b.size(); i++) {
        long long need = (b[i] + x - 1) / x - 1;
        if (need <= k) {
            ans--;
            k -= need;
        } else {
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}