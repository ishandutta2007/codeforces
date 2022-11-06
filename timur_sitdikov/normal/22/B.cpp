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

char v[27][27];
int s[27][27];

int main()
{   

    int n, m, i1, i2, j1, j2, i, j, mx=-1, cur;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++)
        scanf("%s", &v[i+1][1]);
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            v[i][j]-='0';
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            s[i][j]=s[i][j-1]+v[i][j];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            s[i][j]+=s[i-1][j];
    for(i1=1; i1<=n; i1++)
        for(j1=1; j1<=m; j1++)
            for(i2=i1; i2<=n; i2++)
                for(j2=j1; j2<=m; j2++)
                    if (s[i2][j2]-s[i2][j1-1]-s[i1-1][j2]+s[i1-1][j1-1]==0)
                    {
                        cur=2*(i2-i1+1+j2-j1+1);
                        if (cur>mx) mx=cur;
                    }
    printf("%d", mx);

}