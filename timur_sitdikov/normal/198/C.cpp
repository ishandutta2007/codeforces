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
using namespace std;
#define point pair<double, double>
#define xx first
#define yy second

double dimension(point &pt1, point &pt2, point &pt3)
{return (pt2.xx-pt1.xx)*(pt3.yy-pt1.yy)-(pt3.xx-pt1.xx)*(pt2.yy-pt1.yy);}

double sc_pr(point &pt1, point &pt2, point &pt3)
{return (pt2.xx-pt1.xx)*(pt3.xx-pt1.xx)+(pt2.yy-pt1.yy)*(pt3.yy-pt1.yy);}

double dis(point& pt1, point& pt2)
{return (pt2.xx-pt1.xx)*(pt2.xx-pt1.xx)+(pt2.yy-pt1.yy)*(pt2.yy-pt1.yy);}

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    point a, c, b, o;
    double vp, v, r, R2, tmp, f, t, tlim=100000., p, q, R, eps=1e-9, al, d2, bt, t2, v1, v2;
    cin >> c.xx >> c.yy >> vp >> a.xx >> a.yy >> v >> r;
    R2=c.xx*c.xx+c.yy*c.yy;
    R=sqrt(R2+0.);
    o.xx=o.yy=0;
    for(p=0., q=tlim; p+eps<q; )
    {
        t=(p+q)/2.;
        al = vp*t/R;
        b.xx = c.xx * cos(al) - c.yy*sin(al);
        b.yy = c.yy * cos(al) + c.xx*sin(al);
        f=0;
        if (sc_pr(a, o, b)>0 && sc_pr(b, a, o)>0)
        {
            tmp=dimension(o, b, a);
            v1=tmp*tmp;
            v2=r*r*dis(a, b);
            if (v1<v2)
            {
                f=1;
                bt=acos(sc_pr(o, a, b)/sqrt(dis(a,o)*dis(b,o)+0.))-acos(r/sqrt(dis(a, o)+0.))-acos(r/R);
                d2=sqrt(a.xx*a.xx+a.yy*a.yy-r*r+0.)+sqrt(R2-r*r+0.)+r*bt;
            }
        }
        if (!f) d2=sqrt(dis(a, b)+0.);
        t2=d2/v;
        if (t2<t) q=t;
        else p=t;
    }
    printf("%.9lf", t);

}