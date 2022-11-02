#include <stdio.h>
#include <map>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std ;

LL f[20], n;

int main () {
    f[0] = 1;
    for (int i = 1; i <= 10; i++) f[i] = f[i - 1] * 10;
    cin >> n;
    LL res = 0;
    for (int i = 0; i <= 9; i++) {
        if (n >= f[i]) {
            LL t = min (n, f[i + 1] - 1);
//            cout << i <<' ' << t << endl;
            res += (t - f[i] + 1) * (i + 1);
        }
    }
    cout << res << endl;
}