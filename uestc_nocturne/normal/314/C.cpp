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
const int V=1000100;
const int N=1000000;
const int P=1000000007;
int tr[V];
void update(int k,int v)
{
    while(k<=N)
    {
        tr[k]=(tr[k]+v)%P;
        k+=k&-k;
    }
}
int read(int k)
{
    int ret=0;
    while(k)
    {
        ret=(ret+tr[k])%P;
        k-=k&-k;
    }
    return ret;
}
int vis[V],a[V],is[V],n,ct[V],pr[V];
int main()
{
    while(~scanf("%d",&n))
    {
        memset(vis,0,sizeof(vis));
        memset(is,0,sizeof(is));
        memset(pr,-1,sizeof(pr));
        memset(tr,0,sizeof(tr));
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(int i=n-1;i>=0;i--)
        if(!vis[a[i]])
        {
            is[i]=1;
            vis[a[i]]=i;
        }
        else
        {
            pr[vis[a[i]]]=i;
            vis[a[i]]=i;
        }
        int ret=0;
        for(int i=0;i<n;i++)
        {
            int te=a[i];
            //if(pr[i]==-1)
            te=(LL)te*(1+read(a[i]))%P;
            //else
            //te=(LL)te*read(a[i])%P;
            if(is[i])ret=(ret+te)%P;
            ct[i]=te;
            ct[i]+=read(a[i]-1);
            ct[i]-=read(a[i]);
            ct[i]%=P;
            if(ct[i]<0)ct[i]+=P;
            update(a[i],ct[i]);
        }
        printf("%d\n",ret);
    }
}