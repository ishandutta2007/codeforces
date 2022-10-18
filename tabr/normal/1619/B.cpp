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
        long long n;
        cin >> n;
        long long ans = 0;
        for (long long i = 1; i * i <= n; i++) {
            ans++;
        }
        for (long long i = 1; i * i * i <= n; i++) {
            long long j = llround(sqrtl(i * i * i));
            while (j * j < i * i * i) {
                j++;
            }
            while (j * j > i * i * i) {
                j--;
            }
            if (j * j != i * i * i) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}