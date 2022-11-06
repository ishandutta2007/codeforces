#include<stdio.h>
long long gcd(long long x, long long y){if(y==0)return x; else return gcd(y, x%y);}
long long comp(long long x, long long y)
{
    long long re = 0;
    while(x)
    {
        if(x%2 == 1)
        {
            if(y == -1) return -1;
            re += y;
            if(re < 0) return -1;
        }
        x = x/2;
        y = y*2; if(y<0) y = -1;
    }
    return re;
}
long long min(long long x, long long y){return x>y?y:x;}
int main()
{
    long long t, w, b;
    scanf("%lld%lld%lld", &t, &w, &b);
    if(w>b){ long long t = b; b = w; w = t;}
    long long g = gcd(w, b);
    long long l = comp(w/g, b);
    long long q, m;
    if(l == -1){q=0; m=t;}
    else {q = t/l; m = t%l;}
    long long a;
    a = q*w + min(m, w-1);
    g = gcd(a, t);
    printf("%lld/%lld", a/g, t/g);
    return 0;
}