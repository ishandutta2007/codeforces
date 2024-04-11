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
    long long v, x, n, m, i, j, f=0;
    scanf("%I64d %I64d %I64d", &n, &m, &v);
    if (m<n-1 || m>(n-1)*(n-2)/2+1)
    {printf("-1"); return 0;}
    x=(v==n? 1: n);
    for(f=0, i=1; i<=n; i++)
        if (i!=v) {printf("%I64d %I64d\n", i, v); f++;}
    if  (f==m) return 0;
    for(i=1; i<=n; i++)
        for(j=i+1; j<=n; j++)
        {
            
            if (i==x || j==x || i==v || j==v) continue;
            printf("%I64d %I64d\n", i, j);
            f++;
            if (f==m) return 0;
        }
}