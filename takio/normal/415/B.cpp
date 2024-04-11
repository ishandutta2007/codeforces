#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main () {
    long long n, a, b, x;
    cin >> n >> a >> b;
    for (long long i = 1; i <= n; i++) {
        cin >> x;
        if (i != 1) cout << ' ';
        long long w = x * a / b;
        long long f = 0, e = x;
        while (f + 1 < e) {
            long long mid = (f + e) / 2;
            if (mid * a / b < w) f = mid;
            else e = mid;
        }
        if (w) cout << x - e;
        else cout << x;
    }
}