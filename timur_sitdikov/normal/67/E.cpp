#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx real()
#define yy imag()

const int maxn = 1005;
const double EPS = 1e-9;

point pt[maxn];

long long gcd(long long a, long long b){
    return b? gcd(b, a % b): a;
}

long long x[maxn], y[maxn];

double cross(point &a, point &b, point &c){
    return imag(conj(b - a) * (c - a));
}

bool eq(double a, double b){
    return fabs(a - b) < EPS;
}

bool lt(double a, double b){
    return a + EPS < b;
}

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    point offset, rotation, aa, bb;
    int n, i, ans, ansa, ansb;
    long long stepx, stepy, g;
    double xa, xb, curx, step;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        pt[i] = point((double)x[i], (double)y[i]);
    }
    offset = pt[0];
    for(i = 0; i < n; i++)
        pt[i] -= offset;
    rotation = pt[1];
    for(i = 0; i < n; i++)
        pt[i] = pt[i] / rotation * abs(rotation);
    xa = 0., xb = pt[1].xx;
    for(i = 2; i < n; i++){
        if (eq(pt[i - 1].yy, pt[i].yy)){
            if (pt[i - 1].xx < pt[i].xx){
                printf("0");
                return 0;
            }
            continue;
        }
        curx = cross(pt[0], pt[i - 1], pt[i]) / (pt[i].yy - pt[i - 1].yy);
        if (lt(pt[i - 1].yy, pt[i].yy)){
            
            if (curx > xa)
                xa = curx;
        }
        else{
            if (curx < xb)
                xb = curx;
        }
        if (lt(xb, xa)){
            printf("0");
            return 0;
        }
    }
    g = gcd(x[1] - x[0], y[1] - y[0]);
    stepx = (x[1] - x[0]) / g;
    stepy = (y[1] - y[0]) / g;
    step = sqrt(stepx * stepx + stepy * stepy + 0.);
    ansb = (int)((xb + EPS) / step) + 1;
    ansa = (xa - EPS < EPS? 0: (int)((xa - EPS) / step) + 1);
    ans = ansb - ansa;
    cout << ans;
}