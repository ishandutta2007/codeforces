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
const LL ooo=1000000001;
const LL oo=ooo*ooo;
int a[V],c[V],n,Q,c0,c1;
LL mx[V],v0,v1;
int main()
{
    while(~scanf("%d%d",&n,&Q))
    {
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(int i=0;i<n;i++)
        scanf("%d",&c[i]);
        while(Q--)
        {
            int A,B;
            scanf("%d%d",&A,&B);
            for(int i=1;i<=n;i++)mx[i]=-oo;
            c0=c1=n+1;v0=v1=0;
            for(int i=0;i<n;i++)
            {
                LL tmp=(LL)a[i]*A+mx[c[i]];
                if(c0!=c[i])tmp=max(tmp,(LL)a[i]*B+v0);
                else tmp=max(tmp,(LL)a[i]*B+v1);
                mx[c[i]]=max(mx[c[i]],tmp);
                if(tmp<=v1)continue;
                if(tmp<=v0)
                {
                    if(c0==c[i])continue;
                    c1=c[i];v1=tmp;
                }
                else
                {
                    if(c0!=c[i])c1=c0,v1=v0;
                    c0=c[i];v0=tmp;
                }
            }
            LL ret=0;
            for(int i=1;i<=n;i++)ret=max(ret,mx[i]);
            printf("%I64d\n",ret);
        }
    }
}