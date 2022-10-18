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
        auto ask = [&](long long l, long long r) {
            cout << "? " << l << " " << r << endl;
            long long a;
            cin >> a;
            return a;
        };
        long long ax = -1, ay = -1, az = -1;
        long long lo = 1, hi = n;
        while (hi - lo > 1) {
            long long mid = (hi + lo) / 2;
            auto c = ask(1, mid);
            if (c == 0) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        ax = lo;
        long long c = ask(1, n);
        long long d = ask(hi, n);
        ay = ax + c - d + 1;
        long long e = ask(ay, n);
        long long f = ask(ay + 1, n);
        az = ay + e - f;
        cout << "! " << ax << " " << ay << " " << az << endl;
    }
    return 0;
}