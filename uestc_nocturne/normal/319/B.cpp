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
const int V=100100;
int r[V];
int find(int x)
{
    if(x!=r[x])
    r[x]=find(r[x]);
    return r[x];
}
int a[V],n;
int q[2][V],ct[2];
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<=n;i++)r[i]=i;
        a[n]=n+1;
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        memset(ct,0,sizeof(ct));
        int fl=0,te=1;
        int ret=0;
        for(int i=n-1;i>=0;i--)
        if(a[i]>a[i+1])q[0][ct[0]++]=i;
        while(1)
        {
            te=1-fl;
            if(ct[fl]==0)break;
            ret++;
            ct[te]=0;
            for(int i=0;i<ct[fl];i++)
            {
                int id=find(q[fl][i]+1);
                //printf("%d %d\n",q[fl][i],id);
                r[id]=id+1;
            }
            for(int i=0;i<ct[fl];i++)
            {
                int u=q[fl][i];
                if(find(u)!=u)continue;
                int v=find(u+1);
                if(a[u]>a[v])
                {
                    q[te][ct[te]++]=u;
                }
            }
            fl=te;
        }
        printf("%d\n",ret);
    }
}