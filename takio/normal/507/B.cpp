#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define LL long long
using namespace std;

vector <int> g[110] ,res;

int main () {
    LL r, x, y, x2, y2;
    cin >> r >> x >> y >> x2 >> y2;
    double tmp = sqrt((y2 - y) * (y2 - y) + (x2 - x) * (x2 - x));
//    cout << tmp << endl;
    if (fabs((int)(tmp + 0.5) - tmp) < 1e-6 && (int)tmp % (r * 2) == 0) cout << (int)tmp / r / 2 << endl;
    else cout << (int)tmp / (r * 2) + 1;
}