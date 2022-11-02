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
int s[V],ret[V],l[V],r[V],a[V],b[V],R[V],M,n;
bool cmp(int x,int y)
{return a[x]<a[y];}
void lisan()
{
    sort(R,R+n,cmp);
    M=1;int pre=a[R[0]];
    b[1]=a[R[0]];a[R[0]]=1;
    for(int i=1;i<n;i++)
    {
        if(a[R[i]]!=pre)
        {M++;pre=a[R[i]];b[M]=a[R[i]];}
        a[R[i]]=M;
    }
}
int ct[V],Q;
int main()
{
    while(~scanf("%d%d",&n,&Q))
    {
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(int i=0;i<n;i++)R[i]=i;
        lisan();
        for(int i=0;i<Q;i++)
        scanf("%d%d",&l[i],&r[i]);
        memset(ret,0,sizeof(ret));
        memset(ct,0,sizeof(ct));
        for(int i=0;i<n;i++)
        ct[a[i]]++;
        for(int i=1;i<=M;i++)
        {
            if(ct[i]<b[i])continue;
            s[0]=0;
            for(int j=0;j<n;j++)
            if(a[j]==i)s[j+1]=s[j]+1;
            else s[j+1]=s[j];
            for(int j=0;j<Q;j++)
            if(s[r[j]]-s[l[j]-1]==b[i])
            ret[j]++;
        }
        for(int i=0;i<Q;i++)
        printf("%d\n",ret[i]);
    }
}