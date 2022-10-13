#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <cmath>
#include <map>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        long long k, x; cin >> k >> x;
        if (k * k < x) {
            cout << 2 * k - 1 << "\n";
        } else {
            long long lo = 0, hi = 2 * k - 1;
            for (int j = 0; j < 40; j++) {
                long long mid = (lo + hi + 1) / 2;
                long long numMes = 0LL;
                if (mid >= k) {
                    numMes += k * 1LL * (k + 1) / 2;
                    numMes += (mid - k) * 1LL * (3 * k - mid - 1) / 2;
                } else {
                    numMes += mid * 1LL * (mid + 1) / 2;
                }
                if (numMes < x) {
                    lo = mid;
                } else {
                    hi = mid - 1;
                }
            }
            cout << lo + 1 << "\n";
        }
    }
}