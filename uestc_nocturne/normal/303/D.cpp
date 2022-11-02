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
const int MX=100000000;
const int V=100100;
bool check(int x)
{
    for(int i=2;i*i<=x;i++)
    if(x%i==0)return false;
    return true;
}
int Pow(int x,int y,int mod)
{
    int ret=1;
    while(y)
    {
        if(y&1)ret=(LL)ret*x%mod;
        x=(LL)x*x%mod;
        y/=2;
    }
    return ret;
}
int fac[V],fn,n,X;
int main()
{
    while(~scanf("%d%d",&n,&X))
    {
        if(!check(n+1))
        {
            puts("-1");
            continue;
        }
        fn=0;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i!=0)continue;
            fac[fn++]=i;
            if(i*i!=n)fac[fn++]=n/i;
        }
        sort(fac,fac+fn);
        int ret=-1;
        for(int x=X-1,ct=0;ct*fn<=MX&&x>=2;x--,ct++)
        {
            int cd=-1;
            for(int i=0;i<fn;i++)
            if(Pow(x,fac[i],n+1)==1)
            {cd=fac[i];break;}
            if(cd==-1)continue;
            if(cd==n)
            {
                ret=x;break;
                break;
            }
        }
        printf("%d\n",ret);
    }
}