#include<stdio.h>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;

const int N = 200100;

int a[N], b[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, t, an = 0, bn = 0;
    LL sum1 = 0, sum2 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &t);
        if (t > 0) { a[++an] = t; sum1 += a[an]; }
        else {b[++bn] = -t; sum2 += b[bn]; }
    }
//    cout << sum1 << ' ' << sum2 << endl;
    if (sum1 != sum2) {
        if (sum1 > sum2) cout << "first";
        else cout << "second";
        return 0;
    }
    int i = 1;
    while (a[i] && b[i]) {
        if (a[i] != b[i]) {
//            cout << a[i] << ' ' << b[i] << endl;
            if (a[i] > b[i]) cout << "first";
            else cout << "second";
            return 0;
        }
        i++;
    }
    if (a[i]) {
        cout << "first";
        return 0;
    }
    if (b[i]) {
        cout << "second";
        return 0;
    }
    if (t > 0) cout << "first";
    else cout << "second";
}