/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=120;
int set[V];
int find(int x)
{
    if(x!=set[x])set[x]=find(set[x]);
    return set[x];
}
void U(int x,int y)
{
    if(find(x)==find(y))return;
    set[find(x)]=y;
}
int nu[V],ct[V],a[V][V],n,m,x;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++)set[i]=i;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&ct[i]);
            for(int j=0;j<ct[i];j++)
            {scanf("%d",&x);a[i][x]=1;}
        }
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        for(int k=0;k<=m;k++)
        if(a[i][k]&&a[j][k])U(j,i);
        memset(nu,0,sizeof(nu));
        for(int i=1;i<=n;i++)nu[find(i)]=1;
        int ret=-1;
        for(int i=1;i<=n;i++)ret+=nu[i];
        bool all=true;
        for(int i=1;i<=n;i++)if(ct[i]!=0)all=false;
        if(all)ret=n;
        printf("%d\n",ret);
    }
}