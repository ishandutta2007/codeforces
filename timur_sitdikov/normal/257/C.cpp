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

const int maxn = 100005;
const double PI = acos(-1.);

double v[maxn];

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, i, x, y;
    double mx, ans;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> x >> y;
        v[i] = acos(x / sqrt(x * x + y * y + 0.)) * (y >= 0? 1. : -1.);
    }
    sort(v, v + n);
    v[n] = v[0] + 2. * PI;
    mx = 0.;
    for(i = 1; i <= n; i++){
        mx = max(mx, v[i] - v[i - 1]);
    }
    ans = 360. - mx / PI * 180.;
    printf("%.12lf", ans);
}