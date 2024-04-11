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
const int P=1000000000;
int tr[V],N;
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
int f[V],a[V],op,x,y,n,m;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        f[1]=f[2]=1;N=n;
        for(int i=3;i<=n;i++)
        f[i]=(f[i-1]+f[i-2])%P;
        memset(tr,0,sizeof(tr));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            //update(i,(LL)f[i]*a[i]%P);
        }
        while(m--)
        {
            scanf("%d",&op);
            if(op==1)
            {
                scanf("%d%d",&x,&y);
                //int d=y-a[x];
                a[x]=y;
                //d=(LL)f[x]*d%P;
                //if(d<0)d+=P;
                //update(x,d);
            }
            else
            {
                scanf("%d%d",&x,&y);
                //int ret=read(y)-read(x-1);
                //if(ret<0)ret+=P;
                int ret=0;
                for(int i=x;i<=y;i++)
                ret=(ret+(LL)f[i-x+1]*a[i]%P)%P;
                printf("%d\n",ret);
            }
        }
    }
}