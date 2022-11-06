#include <iostream>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <vector>
#include <algorithm>
#include <math.h>
#define int long long
using namespace std;

int x, y, x2, y2, n;

main() {
    cin >> n;
    cin >> x >> y >> x2 >> y2;
    if (x < x2) swap(x, x2);
    if (y < y2) swap(y, y2);
    for (int i = 2; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        x = max(x, a);
        x2 = min(x2, a);
        y = max(y, b);
        y2 = min(y2, b);
    }
    cout << max(abs(y2 - y), abs(x2 - x)) * max(abs(y2 - y), abs(x2 - x));
}