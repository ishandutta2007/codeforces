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
const int oo=1000000000;
struct Node
{
    int id,va;
}q[V];
bool cmp(Node x,Node y)
{
    return x.va<y.va;
}
int a[V],ret[V],n,H;
int main()
{
    while(~scanf("%d%d",&n,&H))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&q[i].va);
            q[i].id=i;
        }
        sort(q,q+n,cmp);
        for(int i=0;i<n;i++)ret[i]=2;
        for(int i=0;i<n;i++)a[i]=q[i].va;
        int mi=a[n-1]+a[n-2]-a[0]-a[1];
        if(n!=2)
        {
            if(mi>a[n-1]+max(a[n-2],a[0]+H)-min(a[0]+a[1]+H,a[1]+a[2]))
            {
                mi=a[n-1]+max(a[n-2],a[0]+H)-min(a[0]+a[1]+H,a[1]+a[2]);
                ret[q[0].id]=1;
            }
        }
        printf("%d\n",mi);
        for(int i=0;i<n;i++)
        {
            if(i)printf(" ");
            printf("%d",ret[i]);
        }puts("");
    }
}