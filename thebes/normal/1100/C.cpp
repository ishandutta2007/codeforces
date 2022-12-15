#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-7;
double n, r, arc, lo, hi, a, x, y;

int main(){
    lo = 0.0; hi = 100000.0;
    cin >> n >> r;
    arc = 360.0/n;
    while(lo+eps<hi){
        double m = (lo+hi)/2.0;
        a = r + m;
        x = (r+m)*cos(arc*3.1415926535/180);
        y = (r+m)*sin(arc*3.1415926535/180);
        double d = sqrt((x-a)*(x-a)+y*y);
        if(d>=2*m) lo=m+eps;
        else hi=m;
    }
    printf("%.7f\n",lo);
    return 0;
}