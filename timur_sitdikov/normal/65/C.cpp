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

const double EPS = 1e-12;

struct my_vector{
    double x, y, z;
    my_vector(){}
    my_vector(double xx, double yy, double zz){
        x = xx;
        y = yy;
        z = zz;
    }
};

my_vector operator + (my_vector &a, my_vector &b){
    return my_vector(a.x + b.x, a.y + b.y, a.z + b.z);
}
my_vector operator - (my_vector &a, my_vector &b){
    return my_vector(a.x - b.x, a.y - b.y, a.z - b.z);
}

my_vector operator * (my_vector &a, double v){
    return my_vector(a.x * v, a.y * v, a.z * v);
}

my_vector operator / (my_vector &a, double v){
    return my_vector(a.x / v, a.y / v, a.z / v);
}

double abs(my_vector &v){
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

const int maxn = 10005;
my_vector pt[maxn];
int n;
my_vector ans, p;
double vs, vp, dis[maxn];

int is_good(double tlim){
    double t, dt, d;
    my_vector tmp;
    int i;
    t = 0;
    for(i = 1; i < n; ){
        dt = dis[i] / vs;
        if ((t + dt) / tlim  + EPS < 1.){
            t += dt;
            i++;
        }
        else{
            tmp = pt[i] - pt[i - 1];
            tmp = tmp * (tlim - t) / dt;
            tmp = tmp + pt[i - 1];
            break;
        }
    }
    if (i == n){
        tmp = pt[n - 1];
    }
    d = abs(p - tmp) / vp;
    ans = tmp;
    return d / tlim <= 1. + EPS;
}

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int i;
    double l, r, tt, mid;
    cin >> n;
    n++;
    for(i = 0; i < n; i++)
        cin >> pt[i].x >> pt[i].y >> pt[i].z;
    cin >> vp >> vs;
    cin >> p.x >> p.y >> p.z;   
    l = r = 0.;
    for(i = 1; i < n; i++){
        dis[i] = abs(pt[i] - pt[i - 1]);
        r += dis[i] / vs;
    }
    tt = abs(p - pt[n - 1]) / vp;
    if (tt / r > 1. + EPS){
        printf("NO");
        return 0;
    }
    if (abs(p - pt[0]) < EPS){
        ans = pt[0];
        printf("YES\n%.12lf\n%.12lf %.12lf %.12lf", 0.0, ans.x, ans.y, ans.z);
        return 0;
    }
    for(; l + EPS < r && l / r + EPS < 1.;){
        mid = (l + r) / 2.;
        if (is_good(mid))
            r = mid;
        else
            l = mid;
    }
    printf("YES\n%.12lf\n%.12lf %.12lf %.12lf", l, ans.x, ans.y, ans.z);
}