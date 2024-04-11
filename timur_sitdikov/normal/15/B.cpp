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

long long llabs(long long a)
{return a<0? -a: a;}

int main()
{   
    long long s, x1, y1, x2, y2, x, y, n, m, ans;
    int t, i;
    scanf("%d", &t);
    for(i=0; i<t; i++)
    {
        scanf("%I64d %I64d %I64d %I64d %I64d %I64d", &n, &m, &x1, &y1, &x2, &y2);
        ans=0;
        x=llabs(x2-x1); y=llabs(y2-y1);
        x=n-x; y=m-y;
        ans+=2*x*y;
        if (x>n-x && y>m-y) ans-=(x-(n-x))*(y-(m-y));
        ans=m*n-ans;
        printf("%I64d\n", ans);
    }
}