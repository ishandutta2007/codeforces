#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int a[100010];

int main () {
    int n;
    cin >> n;
    a[n + 1] = 1e9 + 10;
    for (int i = 1; i <= n; i++)
    {
        scanf ("%d", &a[i]);
    }
    int flag = 0, s = 0, f, e = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < a[i - 1]) {if (!flag) s++, f = i - 1; flag = 1; }
        else {if (flag == 1) e = i - 1;flag = 0;}
    }
//    cout <<s << endl;
//    cout << f << ' ' << e << endl;
    if (e == 0) e = n;
    if (s == 0) {cout << "yes\n"; cout << "1 1"; return 0;}
    if (s > 1 || a[f] > a[e + 1] || a[e] < a[f - 1]) {cout << "no\n"; return 0;}
//    cout << f << ' ' << e;
    for (int i = f; i < e; i++)
    {
        if (a[i] < a[i + 1]) {cout << "no\n"; return 0;}
    }
    cout << "yes\n";
    cout << f << ' ' << e;
}