#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
const double pi = acos(-1);
double n, m;
int main()
{
    scanf("%lf%lf", &n, &m);
    double alpha = pi * (n - 2) / (2 * n);
    printf("%.8lf", cos(alpha) * m / (1 - cos(alpha)));
    return 0;
}