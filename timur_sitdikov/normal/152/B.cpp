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

int main()
{   
    long long xc, yc, x, y, ax, ay, ans=0, n, m, k, i, mn, bi=2000000000;
    scanf("%I64d %I64d %I64d %I64d %I64d", &n, &m, &xc, &yc, &k);
    xc--; yc--;
    for(i=0; i<k; i++)
    {
        scanf("%I64d %I64d", &x, &y);
        ax=ay=bi;
        if (x<0) ax=-xc/x;
        else if (x>0) ax=(n-1-xc)/x;
        if (y<0) ay=-yc/y;
        else if (y>0) ay=(m-1-yc)/y;
        mn=min(ax, ay);
        ans+=mn;
        xc+=mn*x; yc+=mn*y;
    }
    printf("%I64d", ans);
}