#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define LL long long
#define ULL unsigned long long
using namespace std;

int main () {
    int n, m, a, b;
    LL res = 0;
    cin >> n >> m >> a >> b;
    if (m >= n) {
        cout << min (b, a * n);
        return 0;
    }
    if (b < a) {
        while (n > 0) {
            n -= m;
            res += b;
        }
        cout << res << endl;
        return 0;
    }
    if (b < a * m) {
        while (n - m >= 0) {
            n -= m;
            res += b;
        }
    }
    while (n > 0) {
            n --;
            res += a;
    }
    cout << res << endl;
}