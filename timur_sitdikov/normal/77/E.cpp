#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex <double>
#define xx real()
#define yy imag()

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    double r, R, x, y, R0, r0, ans, k;
    int t, i;
    scanf("%d", &t);
    for(i = 0; i < t; i++){
        scanf("%lf %lf %lf", &R, &r, &k);
        r0 = (1. / r - 1. / R) / 4.;
        x = (1. / r + 1. / R) / 4.;
        y = k * (1. / r - 1. / R) / 2.;
        R0 = sqrt(x * x + y * y);
        ans = (1. / (R0 - r0) - 1. / (R0 + r0)) / 2.;
        printf("%.12lf\n", ans);
    }
}