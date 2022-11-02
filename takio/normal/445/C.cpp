#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

double v[510];
double c, res = 0;
int main () {
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int j = 1; j <= m; j++)
    {
       scanf ("%d%d%lf", &a, &b, &c);
        double t = (v[a] + v[b]) / c;
        if (res < t)res = t;
    }
    printf("%.20lf", res);
}