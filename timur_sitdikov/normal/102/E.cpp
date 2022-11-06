#include <stdio.h>

int check(long long xa, long long ya, long long xc, long long yc, long long xb, long long yb)
{
    long long a1, b1, c1, a2, b2, c2, a3, b3, c3, a4, b4, c4, c0, d0, c, d;
    long long x1, y1, x2, y2, x3, y3, x4, y4, f1, f2;
    if (xc==0 && yc==0)
    {
        if (xa==xb && ya==yb) return 1;
        return 0;
    }
    x1=xa; y1=ya; x2=x1+xc; y2=y1+yc;
    x3=xa-yc; y3=ya+xc; x4=x3+xc; y4=y3+yc;
    a1=y2-y1; b1=x1-x2; c1=x2*y1-x1*y2;
    a2=y4-y3; b2=x3-x4; c2=x4*y3-x3*y4;
    a3=y3-y1; b3=x1-x3; c3=x3*y1-x1*y3;
    a4=y4-y2; b4=x2-x4; c4=x4*y2-x2*y4;
    c0=c2-c1;
    d0=c4-c3;
    c=-a1*xb-b1*yb;
    d=b1*xb-a1*yb;
    f1=f2=0;
    if (c==c0 && c0==0) f1=1;
    if (c0==0 && c!=0) f1=-1;
    if (!f1) 
        if (!((c-c1)%c0)) f1=1;
        else f1=-1;
    if (d==d0 && d0==0) f2=1;
    if (d0==0 && d!=0) f2=-1;
    if (!f2) 
        if (!((d-c3)%d0)) f2=1;
        else f2=-1;
    if (f1+f2==2) return 1;
    return 0;
}

int main()
{
    long long xa, ya, xc, yc, xb, yb;
    scanf("%lld %lld %lld %lld %lld %lld", &xa, &ya, &xb, &yb, &xc, &yc);
    if (check(xa, ya, xc, yc, xb, yb)) {printf("YES"); return 0;}
    if (check(-xa, -ya, xc, yc, xb, yb)) {printf("YES"); return 0;}
    if (check(-ya, xa, xc, yc, xb, yb)) {printf("YES"); return 0;}
    if (check(ya, -xa, xc, yc, xb, yb)) {printf("YES"); return 0;}
    printf("NO");
}