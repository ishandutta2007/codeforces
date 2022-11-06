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

char c[105][105], col[205];

int main()
{   
    long long mod=1000000007, i, j, k, n, m, cur, ans=1;
    scanf("%I64d %I64d", &n, &m);
    for(i=0; i<n; i++)
        scanf("%s", &c[i]);
    for(j=0; j<m; j++)
    {
        for(k=0; k<200; k++) col[k]=0;
        cur=0;
        for(i=0; i<n; i++)
            col[c[i][j]]=1;
        for(k=0; k<200; k++) cur+=col[k];
        ans=(ans*cur)%mod;
    }
    printf("%I64d", ans);
}