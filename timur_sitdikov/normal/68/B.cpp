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
#define xx first
#define yy second

const int maxn = 10005;
double a[maxn];
const double EPS = 1e-9;

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, i;
    double l, r, mid, p, difp, difn;
    cin >> n >> p;
    p /= 100.;
    for(i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    l = a[0], r = a[n - 1];
    for(; r - l > EPS; ){
        mid = (l + r) / 2.;
        difp = difn = 0.;
        for(i = 0; i < n; i++){
            if (a[i] > mid)
                difp += a[i] - mid;
            else
                difn += mid - a[i];
        }
        if (difp * (1. - p) < difn){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    printf("%.12lf", r);
}