#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;

const int N = 100100;

int main () {
    LL x1, x2, y1, y2, n, a, b, c, res = 0;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c;
        LL t1 = a * x1 + b * y1 + c;
        LL t2 = a * x2 + b * y2 + c;
        if (t1 < 0 && t2 > 0 || t1 > 0 && t2 < 0) res++;
    }
    cout << res << endl;
}