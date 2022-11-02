#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#define pii pair <int, int>
#define xx first
#define yy second
#define LL long long
using namespace std;

const int N = 100100;

int main () {
//    freopen ("in.txt", "r", stdin);
    int x1, x2, y1, y2;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        int now = 1;
        while (x1 + y1 && x2 + y2) {
            now ^= 1;
//            cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << now << endl;
            if (now == 0) {
                if (x1 == 0) {
                    if (x1 == x2 && y1 - 1 == y2) continue;
                    y1--;
                    continue;
                }
                if (y1 == 0) {
                    if (x1 - 1 == x2 && y1 == y2) continue;
                    x1--;
                    continue;
                }
                if (y1 - x1 < y2 - x2) {
                    if (x1 - 1 == x2 && y1 == y2) continue;
                    x1--;
                } else {
                    if (x1 == x2 && y1 - 1 == y2) continue;
                    y1--;
                }
            } else {
                if (x2 == 0) {
                    if (x1 == x2 && y1 == y2 - 1) continue;
                    y2--;
                    continue;
                }
                if (y2 == 0) {
                    if (x1 == x2 - 1 && y1 == y2) continue;
                    x2--;
                    continue;
                }
                if (x1 == x2 - 1 && y1 == y2 - 1) continue;
                y2--, x2--;
            }
        }
        if (x1 == 0 && y1 == 0) cout << "Polycarp\n";
        else cout << "Vasiliy\n";
    }
}