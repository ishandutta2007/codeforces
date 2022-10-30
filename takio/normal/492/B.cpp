#include<stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int a[1010];
int main () {
    int n, l;
    cin >> n >> l;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort (a + 1, a + 1 + n);
    int mx = 0;
    for (int i = 2; i <= n; i++) {
        mx = max (mx, a[i] - a[i - 1]);
    }
    double res = max (1.0 * mx / 2, 1.0 * max (a[1] - 0, l - a[n]));
    printf ("%.10f", res);
}