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

long long x[100005][2];

int main()
{   
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    long long a[2], b[2], i, j, i1, p, n, q, r;
    scanf("%I64d %I64d %I64d %I64d", &n, &p, &a[0], &a[1]);
    for(i=0; i<n; i++)
    {scanf("%I64d %I64d", &x[i][0], &x[i][1]);}
    r=p%n; q=p/n;
    for(j=0; j<2; j++)
    {
        for(b[j]=0, i=n-1, i1=1; i>=0; i--, i1=-i1)
            b[j]+=x[i][j]*i1;
        b[j]*=2;
        if (n&1)
        {if (q&1) a[j]=b[j]-a[j];}
        else a[j]+=b[j]*q;
        for(i=0; i<r; i++)
            a[j]=2*x[i][j]-a[j];
    }
    printf("%I64d %I64d", a[0], a[1]);
}