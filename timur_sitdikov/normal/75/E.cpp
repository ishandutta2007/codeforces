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

const int maxn = 35;
const double EPS = 1e-9;
point pt[maxn];

int cross(point &a, point &b, point &c){
    double d = imag(conj(b - a) * (c - a));
    if (fabs(d) < EPS)
        return 0.;
    if (d < 0.)
        return -1;
    return 1;
}

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, i, j, fl;
    point s, f, u, d;
    double l, lu, ld, xs, ys, xf, yf, ans, ans2, x0, dx;
    set<double> x;
    cin >> xs >> ys >> xf >> yf;
    s = point(xs, ys);
    f = point(xf, yf);
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> xs >> ys;
        pt[i] = point(xs, ys);
    }
    fl = 0;
    for(i = 0; i < n; i++)
        pt[i] -= s;
    f -= s;
    s = point(0., 0.);
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if (cross(s, f, pt[i]) * cross(s, f, pt[j]) < 0){
                if (cross(pt[i], pt[j], s) * cross(pt[i], pt[j], f) < 0) {
                    fl = 1;
                }
            }
        }
    }
    if (!fl){
        ans = abs(f);
        printf("%.12lf", ans);
        return 0;
    }
    for(i = 0; i < n; i++){
        pt[i] = pt[i] / f * abs(f);
    }
    f = point(abs(f), 0.);
    for(i = 0; i < n; i++){
        if (fabs(pt[i].yy) < EPS){
            x.insert(pt[i].xx);
        }
    }
    lu = ld = 0.;
    for(i = 0; i < n; i++){
        if (pt[i].yy * pt[(i + n - 1) % n].yy > -EPS){
            l = abs(pt[i] - pt[(i + n - 1) % n]);
            if (pt[i].yy > EPS || pt[(i + n - 1) % n].yy > EPS)
                lu += l;
            else
                ld += l;
            continue;
        }
        if (pt[i].yy < 0.){
            d = pt[i];
            u = pt[(i + n - 1) % n];
        }
        else{
            u = pt[i];
            d = pt[(i + n - 1) % n];
        }
        l = abs(d - u);
        lu += l * u.yy / (u.yy - d.yy);
        ld += l * d.yy / (d.yy - u.yy);
        x0 = d.xx - d.yy * (u.xx - d.xx) / (u.yy - d.yy);
        x.insert(x0);
    }
    dx = -(*(x.begin())) + (*(x.rbegin()));
    ans = abs(f) - dx;
    ans2 = min(lu, ld);
    ans2 = min(ans2, 2. * dx);
    ans += ans2;
    printf("%.12lf", ans);
}