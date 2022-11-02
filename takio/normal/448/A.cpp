#include <cstdio>
#include <iostream>
using namespace std;
#define LL long long

int main () {
    int x1, x2, x3, y1, y2, y3, n;
    cin >>x1 >> x2 >> x3 >> y1 >> y2 >> y3 >> n;
    int x = x1 + x2 + x3;
    int y = y1 + y2 + y3;
    if (x == 0) x = -4;
    if (y == 0) y = -9;
    if ((x - 1) / 5 + 1 + (y - 1) / 10 + 1 <= n) cout << "YES\n";
    else cout << "NO\n";
}