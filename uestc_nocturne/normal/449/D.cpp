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
const int N=20;
const int V=(1<<20)+10;
const int P=1000000007;
int Pow(int x,int y)
{
    int ret=1;
    while(y)
    {
        if(y&1)ret=(LL)ret*x%P;
        x=(LL)x*x%P;y/=2;
    }
    return ret;
}
void utf(int *a,int l,int r)
{
    if(l+1!=r)
    {
        int mid=(l+r)/2;
        for(int i=0;i<mid-l;i++)
        {
            a[l+i]-=a[mid+i];
            if(a[l+i]<0)a[l+i]+=P;
        }
        utf(a,l,mid);
        utf(a,mid,r);
    }
}
void tf(int *a,int l,int r)
{
    if(l+1!=r)
    {
        int mid=(l+r)/2;
        tf(a,l,mid);
        tf(a,mid,r);
        for(int i=0;i<mid-l;i++)
        {
            a[l+i]+=a[mid+i];
            if(a[l+i]>=P)a[i+l]-=P;
        }
    }
}
int cnt[V],q[V];
int n,x,pro[V];
int pt[V];
int main()
{
    pt[0]=1;
    for(int i=1;i<(1<<N);i++)
    pt[i]=pt[i-1]*2%P;
    while(~scanf("%d",&n))
    {
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            cnt[x]++;
        }
        tf(cnt,0,(1<<N));
        for(int i=0;i<(1<<N);i++)
        pro[i]=pt[cnt[i]];
        utf(pro,0,(1<<N));
        printf("%d\n",pro[0]);
    }
}