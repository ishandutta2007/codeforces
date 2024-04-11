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

const double eps=1e-9;

struct circle
{
    point o;
    double r;
};

struct line
{
    double a, b, c;
};

double dis(point &a, point &b)
{
    point tmp=a-b;
    double d=tmp.xx*tmp.xx+tmp.yy*tmp.yy;
    if (d<eps)
        d=0.;
    return sqrt(d);
}

line find_line(point &a, point &b)
{
    line ans;
    ans.a=b.yy-a.yy;
    ans.b=a.xx-b.xx;
    ans.c=b.xx*a.yy-a.xx*b.yy;
    return ans;
}

point intersect(line &l1, line &l2)
{
    double x, y;
    x=(-l1.c*l2.b+l2.c*l1.b)/(l1.a*l2.b-l2.a*l1.b);
    y=(-l1.a*l2.c+l2.a*l1.c)/(l1.a*l2.b-l2.a*l1.b);
    point ans(x, y);
    return ans;
}

vector<point> intersect(circle &c, line &l)
{
    vector<point> ans;
    point p, p1, v;
    line tmp;
    double d;
    p1=c.o+point(l.a, l.b);
    tmp=find_line(c.o, p1);
    p=intersect(l, tmp);
    d=dis(c.o, p);
    if (fabs(d-c.r)<eps)
    {
        ans.pb(p);
        return ans;
    }
    if (c.r<d)
        return ans;
    v=point(-l.b, l.a);
    v/=abs(v);
    v*=sqrt(c.r*c.r-d*d);
    ans.pb(p+v);
    ans.pb(p-v);
    return ans;
}

vector<point> intersect(circle &c1, circle &c2)
{
    vector<point> ans;
    line tmp;
    double d=dis(c1.o, c2.o);
    if (c1.r+c2.r+eps<d || c1.r+d+eps<c2.r || c2.r+d+eps<c1.r)
        return ans;
    tmp.a=-2.*(c1.o.xx-c2.o.xx);
    tmp.b=-2.*(c1.o.yy-c2.o.yy);
    tmp.c=c1.o.xx*c1.o.xx-c2.o.xx*c2.o.xx
         +c1.o.yy*c1.o.yy-c2.o.yy*c2.o.yy
         -c1.r*c1.r+c2.r*c2.r;
    return intersect(c1, tmp);
}

int get_figure(circle &c1, circle &c2, circle &c_ans, line &l_ans)
{
    double a, b, c, A, B, C, D, E, x, y;
    if (fabs(c1.r-c2.r)<eps)
    {
        a=-2.*c2.r*c2.r*c1.o.xx+2.*c1.r*c1.r*c2.o.xx;
        b=-2.*c2.r*c2.r*c1.o.yy+2.*c1.r*c1.r*c2.o.yy;
        c=c2.r*c2.r*c1.o.xx*c1.o.xx-c1.r*c1.r*c2.o.xx*c2.o.xx
         +c2.r*c2.r*c1.o.yy*c1.o.yy-c1.r*c1.r*c2.o.yy*c2.o.yy;
        l_ans.a=a;
        l_ans.b=b;
        l_ans.c=c;
        return 0;
    }
    A=C=c2.r*c2.r-c1.r*c1.r;
    B=-2.*c2.r*c2.r*c1.o.xx+2.*c1.r*c1.r*c2.o.xx;
    D=-2.*c2.r*c2.r*c1.o.yy+2.*c1.r*c1.r*c2.o.yy;
    E=c2.r*c2.r*c1.o.xx*c1.o.xx-c1.r*c1.r*c2.o.xx*c2.o.xx
     +c2.r*c2.r*c1.o.yy*c1.o.yy-c1.r*c1.r*c2.o.yy*c2.o.yy;
    B/=A;
    D/=A;
    E/=A;
    A=C=1.;
    x=-B/2.;
    y=-D/2.;
    c_ans.o=point(x, y);
    c_ans.r=B*B/4.+D*D/4.-E;
    if (fabs(c_ans.r)<eps)
        c_ans.r=0.;
    if (c_ans.r<0.)
        return -1;
    c_ans.r=sqrt(c_ans.r);
    return 1;
}

istream & operator >> (istream &s, point &a)
{
    double x, y;
    s >> x >> y;
    a=point(x, y);
    return s;
}

istream & operator >> (istream &s, circle &c)
{
    s >> c.o >> c.r;
    return s;
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    circle c1, c2, c3, b1, b2;
    line a1, a2;
    vector<point> goods;
    point ans;
    int f1, f2;
    double d1, d2;
    cin >> c1 >> c2 >> c3;
    f1=get_figure(c1, c2, b1, a1);
    f2=get_figure(c1, c3, b2, a2);
    if (!f1 && !f2)
        goods.pb(intersect(a1, a2));
    else if (!f1 && f2==1)
        goods=intersect(b2, a1);
    else if (f1==1 && !f2)
        goods=intersect(b1, a2);
    else if (f1==1 && f2==1) 
        goods=intersect(b1, b2);
    if (goods.empty())
    {
        return 0;
    }
    ans=goods[0];
    if (goods.size()>1)
    {
        d1=dis(goods[0], c1.o);
        d2=dis(goods[1], c1.o);
        if (d2<d1)
            ans=goods[1];
    }
    printf("%.12lf %.12lf", ans.real(), ans.imag());
}