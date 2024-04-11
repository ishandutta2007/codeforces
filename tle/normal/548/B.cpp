#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
int n,m,q,mkx[100001];
bool s[1001][1001];
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int ss;
            scanf("%d",&ss);
            s[i][j+1]=ss;
        }
    }
    for(int i=1;i<=n;i++)
    {
        int mm=0;
        for(int j=1;j<=m;j++)
        {
            if(!s[i][j]) continue;
            int tt;
            for(int k=j;k<=m;k++)
            {
                if(!s[i][k]) break;
                tt=k;
            }
            mm=max(mm,tt-j+1);
        }
        mkx[i]=mm;
    }
    for(int i=1;i<=q;i++)
    {
        int aa,bb;
        scanf("%d%d",&aa,&bb);
        s[aa][bb]=!s[aa][bb];
        int mm=0;
        for(int j=1;j<=m;j++)
        {
            if(!s[aa][j]) continue;
            int tt;
            for(int k=j;k<=m;k++)
            {
                if(!s[aa][k]) break;
                tt=k;
            }
            mm=max(mm,tt-j+1);
        }
        mkx[aa]=mm;
        int ms=0;
        for(int j=1;j<=n;j++) ms=max(ms,mkx[j]);
        printf("%d\n",ms);
    }
}