#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct fruit {
    int a, b;
}f[3010];

bool cmp(fruit a, fruit b){
    return a.a < b.a;
}

int main () {
     int n, m, k;
     cin >> n >> m >> k;
     if (m == 1){
        int x = 1;
        for (int i = 1; i <= k - 1; i++){
            cout << 2 << ' ' << x << ' ' << 1 << ' ' << x + 1 << ' ' << 1 << endl;
            x += 2;
        }
        cout << n * m - 2 * k + 2;
        for (int i = 1; i <= n * m - 2 * k + 2; i++){
            cout << ' ' << x << ' ' << 1;
            x += 1;
        }
        return 0;
     }
     int x = 1, y = 1, d = 1;
     for (int i = 1; i <= k - 1; i++){
        if (y + d > m)
            cout << 2 << ' ' << x << ' ' << y << ' ' << x + 1 << ' ' << y << endl;
        else
            cout << 2 << ' ' << x << ' ' << y << ' ' << x << ' ' << y + d << endl;
        y += 2 * d;
        if (y > m){
            x++;
            d = -d;
            if (y == m + 2) y = m - 1;
            else y = m;
        }
        if (y <= 0){
            x++;
            d = -d;
            y = 1;
        }
     }
     cout << n * m - 2 * k + 2;
     for (int i = 1; i <= n * m - 2 * k + 2; i++){
        cout << ' ' << x << ' ' << y;
        y += d;
        if (y == m + 1) x++, y = m, d = -d;
        if (y == 0) x++, y = 1, d = -d;
     }
}