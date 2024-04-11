#include <stdio.h>
#include <map>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
#define LL long long
using namespace std ;

const int INF = 1e9 + 10;
LL f[120];

int main () {
    LL w, m;
    cin >> w >> m;
    if (w == 2) { cout << "YES"; return 0; }
//    f[0] = 1;
//    for (int i = 1; i <= 100; i++) {
//        f[i] = f[i - 1] * w;
//        if (f[i] > INF) break;
//    }
    while (m != 1) {
        if (m % w == 0) { m /= w; continue; }
        if ((m - 1) % w == 0) { m--; m /= w; continue; }
        if ((m + 1) % w == 0) { m++; m /= w; continue; }
        cout << "NO";
        return 0;
    }
    cout << "YES";
}