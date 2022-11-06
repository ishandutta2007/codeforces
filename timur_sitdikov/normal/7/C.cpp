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

long long gcd(long long a, long long b)
{return b? gcd(b, a%b): a;}

long long gcd2(long long a, long long b, long long *x, long long *y)
{
    if (!b)
    {
        *x=1; *y=0; return a;
    }
    long long x1, y1, g;
    g=gcd2(b, a%b, &x1, &y1);
    *x=y1;
    *y=(x1-a/b*y1);
    return g;
}

int main()
{   
    long long a, b, c, g, x, y, gg;
    scanf("%I64d %I64d %I64d", &a, &b, &c);
    c=-c;
    g=gcd(a, b);
    if (c%g) {printf("-1"); return 0;}
    a/=g; b/=g; c/=g;
    g=gcd2(a, b, &x, &y);
    printf("%I64d %I64d", x*c, y*c);
}