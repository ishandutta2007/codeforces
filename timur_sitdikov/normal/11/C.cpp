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

char c[255][255];
int n, m;
queue <pair<int, int> > qq;

int bfs(int i0, int j0)
{
    int i, j, k, i1, j1, num=1, len, f;
    while(!qq.empty()) qq.pop();
    qq.push(make_pair(i0, j0));
    c[i0][j0]=2;
    i1=i0; j1=j0;
    while(!qq.empty())
    {
        i0=qq.front().first;
        j0=qq.front().second;
        qq.pop();
        for(i=-1; i<=1; i++)
            for(j=-1; j<=1; j++)
                if (c[i0+i][j0+j]==1)
                {
                    c[i0+i][j0+j]=2;
                    qq.push(make_pair(i0+i, j0+j));
                    num++;
                }
    }
    if (num%4) return 0;
    len=num/4; f=0;
    for(i=i1, j=j1, k=0; k<=len; k++, j++)
        if (i<=0 || i>n || j<=0 || j>m || c[i][j]!=2) {f=1; break;}
    for(i=i1+len, j=j1, k=0; k<=len; k++, j++)
        if (i<=0 || i>n || j<=0 || j>m || c[i][j]!=2){f=1; break;}
    for(i=i1, j=j1, k=0; k<=len; k++, i++)
        if (i<=0 || i>n || j<=0 || j>m || c[i][j]!=2){f=1; break;}
    for(i=i1, j=j1+len, k=0; k<=len; k++, i++)
        if (i<=0 || i>n || j<=0 || j>m || c[i][j]!=2) {f=1; break;}
    if (!f) return 1;
    f=0;
    for(i=i1, j=j1, k=0; k<=len; k++, i++, j++)
        if (i<=0 || i>n || j<=0 || j>m || c[i][j]!=2) {f=1; break;}
    for(i=i1+len, j=j1+len, k=0; k<=len; k++, i++, j--)
        if (i<=0 || i>n || j<=0 || j>m || c[i][j]!=2) {f=1; break;}
    for(i=i1, j=j1, k=0; k<=len; k++, i++, j--)
        if (i<=0 || i>n || j<=0 || j>m || c[i][j]!=2) {f=1; break;}
    for(i=i1+len, j=j1-len, k=0; k<=len; k++, i++, j++)
        if (i<=0 || i>n || j<=0 || j>m || c[i][j]!=2) {f=1; break;}
    if (!f) return 1;
    return 0;
}

int main()
{   
    int t, i, j,k,  ans;
    scanf("%d", &t);
    for(k=0; k<t; k++)
    {
        scanf("%d %d", &n, &m);
        for(i=0; i<=n+1; i++)
            for(j=0; j<=m+1; j++)
                c[i][j]=0;
        ans=0;
        for(i=1; i<=n; i++)
            scanf("%s", &c[i][1]);
        for(i=1; i<=n; i++)
            for(j=1; j<=m; j++)
                c[i][j]-='0';
        for(i=1; i<=n; i++)
            for(j=1; j<=m; j++)
                if (c[i][j]==1)
                    ans+=bfs(i, j);
        printf("%d\n", ans);
    }
}