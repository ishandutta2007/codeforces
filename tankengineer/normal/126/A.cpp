#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

long long t1, t2, x1, x2, t0, best1 = 0, best2 = 0;

void update(long long y1, long long y2) {
    if (best1 == 0 && best2 == 0) {
        best1 = y1, best2 = y2;
        return;
    }
    if ((t1 * y1 + t2 * y2) * (best1 + best2) <
        (t1 * best1 + t2 * best2) * (y1 + y2)) {
        best1 = y1, best2 = y2;
    } else if ((t1 * y1 + t2 * y2) * (best1 + best2) ==
               (t1 * best1 + t2 * best2) * (y1 + y2)) {
        if (y1 + y2 > best1 + best2) {
            best1 = y1, best2 = y2;
        }
    }
}

int main() {
    cin >> t1 >> t2 >> x1 >> x2 >> t0;
    if (t1 == t0 && t2 == t0) {
        cout << x1 << ' ' << x2 << endl;
        return 0;
    }
    if (t1 == t0) {
        cout << x1 << ' ' << 0 << endl;
        return 0;
    }
    if (t2 == t0) {
        cout << 0 << ' ' << x2 << endl;
        return 0;
    }
    for (long long i = 0; i <= x1; ++i) {
        long long k = t2 - t0, a = (t0 - t1) * i, j = (a + k - 1) / k;
        if (i == 0) {
            j = x2;
        }
        if (j <= x2) {
            update(i, j);
        }
    }
    cout << best1 << ' ' << best2 << endl;
    return 0;
}