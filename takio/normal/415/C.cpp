#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main () {
    int n, k;
    cin >> n >> k;
    if(n / 2 > k || (n == 1 && k != 0)) {cout << -1; return 0;}
    if(n == 1) {cout << 1; return 0;}
    int f1 = k - n / 2 + 1, f2;
    cout << f1 << ' ' << (f2 = f1 * 2);
    int t = 1;
    for (int i = 4; i <= n; i += 2) {
        while(t == f1 || t == f2 || t + 1 == f1 || t + 1 == f2) t++;
        cout << ' ' << t << ' ' << t + 1;
        t += 2;
    }
    if (n % 2) {
        while(t == f1 || t == f2 || t + 1 == f1 || t + 1 == f2) t++;
        cout << ' ' << t;
    }
}