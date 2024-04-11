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
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        long long a, b;
        cin >> n >> a >> b;
        vector<long long> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        x.insert(x.begin(), 0);
        long long sum = accumulate(x.begin(), x.end(), 0LL);
        long long ans = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            long long t = (a + b) * x[i];
            sum -= x[i];
            t += (sum - x[i] * (n - i)) * b;
            ans = min(ans, t);
        }
        cout << ans << '\n';
    }
    return 0;
}