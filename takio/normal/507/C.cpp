#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define LL long long
using namespace std;

LL f[55];

LL solve (int n, LL m, int k) {
//    cout << n << ' ' << m << ' ' << k << ' ' << f[n - 1] << endl;
    if (n == 0) return 0;
    if (k == 0) {
        if (m <= f[n - 1]) return solve (n - 1, m, 1 - k) + 1;
        return f[n] + solve (n - 1, m - f[n - 1], k);
    }
    if (m <= f[n - 1]) return f[n] + solve (n - 1, m, k);
    return solve (n - 1, m - f[n - 1], 1 - k) + 1;
}

int main () {
    f[0] = 1;
    for (int i = 1; i <= 50; i++) {
        f[i] = f[i - 1] * 2;
//        cout << f[i] << endl;
    }
    int n;
    LL m;
    cin >> n >> m;
    cout << solve (n, m, 0);
}