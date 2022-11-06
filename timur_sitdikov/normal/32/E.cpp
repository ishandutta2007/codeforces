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
#include <complex>
#define pb push_back
#define point complex<long long>
#define dpoint complex<double>

double eps=1e-7;

long long abs(long long v)
{
    return v<0? -v: v;
}

istream& operator >> (istream& s, point & pt)
{
    s >> pt._Val[0] >> pt._Val[1];
    return s;
}

template <class T> int on_seg(complex<T> &a, complex<T> &b, complex<T> &c)
{
    double tmp=imag(conj(b-a)*(c-a));
    if (abs(tmp)>eps)
        return 0;
    if ((a.real()<(c.real()+eps) && c.real()<(b.real()+eps) || 
        b.real()<(c.real()+eps) && c.real()<(a.real()+eps)) &&
        (a.imag()<(c.imag()+eps) && c.imag()<(b.imag()+eps) ||
        b.imag()<(c.imag()+eps) && c.imag()<(a.imag()+eps)))
        return 1;
    return 0;
}

template <class T> int seg_int(complex<T> &a, complex<T> &b, complex<T> &c, complex<T> &d)
{
    if (imag(conj(b-a)*(c-a))*imag(conj(b-a)*(d-a))+eps<0. &&
        imag((b-c)*conj(d-c))*imag((a-c)*conj(d-c))+eps<0.)
        return 1;
    if (on_seg(a, b, c) || on_seg(a, b, d) || on_seg(c, d, a) || on_seg(c, d, b))
        return 1;
    return 0;
}

dpoint find_intersection(dpoint &a, dpoint &b, dpoint &c, dpoint &d)
{
    double d1, d2;
    d1 = imag(conj(c-a)*(b-a));
    d2 = imag(conj(d-a)*(b-a));
    return (d1*d-d2*c)/(d1-d2);
}

dpoint reflect(dpoint a, dpoint b, dpoint c)
{
    return conj((c-a)/(b-a))*(b-a)+a;
}

int seg_int2(point &a, point &b, point &c, point &d)
{
    if (imag(conj(b-a)*(c-a))*imag(conj(b-a)*(d-a))<0 &&
        imag((b-c)*conj(d-c))*imag((a-c)*conj(d-c))<0)
        return 1;
    if (on_seg(a, b, c) && on_seg(a, b, d))
        return 0;
    if (on_seg(c, d, a) && on_seg(c, d, b))
        return 0;
    if (on_seg(a, b, c) || on_seg(a, b, d) || on_seg(c, d, a) || on_seg(c, d, b))
        return 1;
    return 0;
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    point a, b, c, f, o1, o2;
    dpoint da, db, dc, dd, df, do1, do2, doo;
    cin >> f >> c >> o1 >> o2 >> a >> b;
    double al;
    da=a;
    db=b;
    dc=c;
    df=f;
    do1=o1;
    do2=o2;
    if (seg_int2(a, b, c, f))
    {
        printf("NO");
        return 0;
    }
    if (!seg_int(f, c, o1, o2) && !seg_int2(a, b, c, f))
    {
        printf("YES");
        return 0;
    }
    if (imag(conj(b-a)*(c-a))*imag(conj(b-a)*(f-a))<eps)
    {
        printf("NO");
        return 0;
    }
    dd=reflect(da, db, dc);
    doo=find_intersection(da, db, df, dd);
    if (!on_seg(da, db, doo))
    {
        printf("NO");
        return 0;
    }
    if (seg_int(do1, do2, dc, doo) || seg_int(do1, do2, df, doo))
        printf("NO");
    else printf("YES");

    return 0;
    
}