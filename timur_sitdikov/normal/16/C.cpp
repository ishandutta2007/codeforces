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

int main()
{   
    long long x, y, x1, y1, x2=0, y2=0, a, b, g;
    long long mx=0;
    scanf("%I64d %I64d %I64d %I64d", &a, &b, &x, &y);
    g=gcd(x, y);
    x/=g;
    y/=g;
    x1=a-a%x;
    y1=x1/x*y;
    if (y1<=b && y1*x1>=mx)
    {
        mx=y1*x1;
        x2=x1; y2=y1;
    }
    y1=b-b%y;
    x1=y1/y*x;
    if (x1<=a && y1*x1>=mx)
    {
        mx=y1*x1;
        x2=x1; y2=y1;
    }
    printf("%I64d %I64d", x2, y2);
}