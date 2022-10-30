#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define LL long long
#define ULL unsigned long long
using namespace std;

LL n, a, b;

int jug (LL n) {
    for (LL i = min (a, b); i * i <= n; i++) {
        if (n % i == 0) {
            if (i >= a && n / i >= b) {
                cout << n << endl << i << ' ' << n / i;
                return 1;
            }
            if (i >= b && n / i >= a) {
                cout << n << endl << n / i << ' ' << i;
                return 1;
            }
        }
    }
    return 0;
}

int main () {
    cin >> n >> a >> b;
    n *= 6;
    if (a * b >= n) {
        cout << a * b << endl << a << ' ' << b;
        return 0;
    }
    while (1) {
        if (jug (n)) break;
        n++;
    }
}