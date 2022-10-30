#include <cstring>
#include <cstdio>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main () {
    long long n, m, k;
    cin >> n >> m >> k;
    if (k > n + m - 2) {cout << -1; return 0;}
    long long res = 1;
    for (long long i = 0;; i++){
        if (i * i >= n) break;
        if (i > k) break;
        long long an = n / (i + 1);
//        if (an > k) continue;
//        cout << an <<' ' << k - i << ' ' << an * (m / (k - i + 1)) << endl;
        res = max (res, an * (m / (k - i + 1)));
    }
//    if (res == 987283748) cout << 'x';
//    cout << 'xxxx';
    for (long long i = 1; i <= (long long)(sqrt(n) + 1e-9); i++)
    {
        long long d = n / i;
        while (n / d == i) d++;
        d -= 2;
        if (d > k) d = k;
//        cout << d <<' ' << k - d << ' ' <<  i * (m / (k - d + 1)) << endl;
        res = max (res, i * (m / (k - d + 1)));
    }
    cout << res << endl;
}