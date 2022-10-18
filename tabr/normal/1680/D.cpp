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
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long sum = -accumulate(a.begin(), a.end(), 0LL);
    int c = (int) count(a.begin(), a.end(), 0LL);
    if (abs(sum) > k * c) {
        cout << -1 << '\n';
        return 0;
    }
    long long ans = 0;
    for (int z = 0; z < 2; z++) {
        for (int i = 0; i <= n; i++) {
            long long dif = 0;
            int cnt = 0;
            for (int j = i + 1; j <= n; j++) {
                dif += a[j - 1];
                if (a[j - 1] == 0) {
                    cnt++;
                }
                long long low = -cnt * k;
                long long high = cnt * k;
                low = max(low, sum - (c - cnt) * k);
                high = min(high, -sum + (c - cnt) * k);
                debug(i, j, low, high);
                if (low <= high) {
                    ans = max(ans, abs(dif + low));
                }
            }
        }
        for (int i = 0; i < n; i++) {
            a[i] *= -1;
        }
        sum *= -1;
    }
    ans++;
    cout << ans << '\n';
    return 0;
}