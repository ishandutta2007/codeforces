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
const int V=1200;
struct Node
{
    int va,id;
}a[V],b[V];
bool cmp(Node x,Node y)
{
    return x.va>y.va;
}
int n,k,i,x,y,an,bn;
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        an=bn=0;
        double s=0.0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            if(y==1)
            {
                a[an].va=x;
                a[an++].id=i;
            }
            else
            {
                b[bn].va=x;
                b[bn++].id=i;
            }
            s+=x;
        }
        if(k<=an)
        {
            sort(a,a+an,cmp);
            for(i=0;i<k-1;i++)s-=1.0*a[i].va/2.0;
            int mi=1000000020;
            for(i=k-1;i<an;i++)mi=min(mi,a[i].va);
            for(i=0;i<bn;i++)mi=min(mi,b[i].va);
            s-=1.0*mi/2.0;
            printf("%.1f\n",s);
            for(i=0;i<k-1;i++)printf("1 %d\n",a[i].id+1);
            printf("%d",n-k+1);
            for(i=k-1;i<an;i++)printf(" %d",a[i].id+1);
            for(i=0;i<bn;i++)printf(" %d",b[i].id+1);puts("");
        }
        else
        {
            for(i=0;i<an;i++)s-=1.0*a[i].va/2.0;
            printf("%.1f\n",s);
            for(i=0;i<an;i++)printf("1 %d\n",a[i].id+1);
            for(i=0;i+an<k-1;i++)printf("1 %d\n",b[i].id+1);
            printf("%d",n-k+1);
            for(i=k-1-an;i<bn;i++)printf(" %d",b[i].id+1);puts("");
        }
    }
}