#include <cstdio>
#include "math.h"
#include <iostream>
using namespace std;

int main() {
    int r, x1, y1, x2, y2;
    scanf("%d%d%d%d%d", &r, &x1, &y1, &x2, &y2);
    long long d = pow(x1-x2, 2) + pow(y1-y2, 2);

    double s = sqrt(d)/(2*r);
    printf("%.lf", ceil(s));
}