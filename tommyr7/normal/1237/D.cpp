#include <bits/stdc++.h>
#define Maxn 200007
#define inf 1000000007
using namespace std;
int n,a[Maxn];
int max_val[Maxn][21],min_val[Maxn][21];
int bin[Maxn];
int f[Maxn];
int mx=0,mn=inf;
int query_min(int lx,int rx)
{
    int tmp=bin[rx-lx+1];
    return min(min_val[lx][tmp],min_val[rx-(1<<tmp)+1][tmp]);
}
int query_max(int lx,int rx)
{
    int tmp=bin[rx-lx+1];
    return max(max_val[lx][tmp],max_val[rx-(1<<tmp)+1][tmp]);
}
int calc(int pos)
{
    if (pos>n) return calc(pos-n);
    if (f[pos]!=-1) return f[pos];
    int res;
    int pos1,pos2;
    int lx,rx;
    lx=pos+1,rx=pos+n;
    while (rx-lx>1)
    {
        int mid=(lx+rx)/2;
        if (query_max(pos,mid)>a[pos]) rx=mid; else lx=mid;
    }
    if (query_max(pos,lx)>a[pos]) pos1=lx;
    else if (query_max(pos,rx)>a[pos]) pos1=rx;
    else pos1=2*n+1;
    lx=pos+1,rx=pos+n;
    while (rx-lx>1)
    {
        int mid=(lx+rx)/2;
        if (2*query_min(pos,mid)<a[pos]) rx=mid; else lx=mid;
    }
    if (2*query_min(pos,lx)<a[pos]) pos2=lx;
    else if (2*query_min(pos,rx)<a[pos]) pos2=rx;
    else pos2=2*n+1;
    if (pos1<pos2) res=calc(pos1)+pos1-pos; else res=pos2-pos;
    f[pos]=res;
    return res;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        mx=max(mx,a[i]);
        mn=min(mn,a[i]);
    }
    if (mx<=2*mn)
    {
        for (int i=1;i<=n;i++)
            printf("%d ",-1);
        printf("\n");
        return 0;
    }
    for (int i=1;i<=n;i++)
        a[n+i]=a[i];
    for (int i=1;i<=2*n;i++)
    {
        max_val[i][0]=a[i];
        min_val[i][0]=a[i];
    }
    for (int k=1;k<=20;k++)
        for (int i=1;i<=2*n;i++)
        {
            max_val[i][k]=max_val[i][k-1];
            min_val[i][k]=min_val[i][k-1];
            if (i+(1<<(k-1))<=2*n)
            {
                max_val[i][k]=max(max_val[i][k],max_val[i+(1<<(k-1))][k-1]);
                min_val[i][k]=min(min_val[i][k],min_val[i+(1<<(k-1))][k-1]);
            }
        }
    bin[1]=0;
    for (int i=2;i<=2*n;i++)
        bin[i]=bin[i/2]+1;
    memset(f,-1,sizeof(f));
    for (int i=1;i<=n;i++)
        printf("%d ",calc(i));
    printf("\n");
    return 0;
}