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
const int V=300100;
const int N=1000000;
int a[V],K,n;
struct ls{int x,ne;}fac[N*30];
int hd[N+10],KK;
void add(int x,int y)
{
    fac[KK].x=y;
    fac[KK].ne=hd[x];
    hd[x]=KK++;
}
int tr[N+10],sum[N+10],pre[N+10];
void update(int k,int v)
{
    while(k<=N)
    {
        tr[k]+=v;
        k+=k&-k;
    }
}
int read(int k)
{
    int ret=0;
    while(k)
    {
        ret+=tr[k];
        k-=k&-k;
    }
    return ret;
}
int ret[N+10];
int main()
{
    memset(hd,-1,sizeof(hd));KK=0;
    for(int i=1;i<=N;i++)
    for(int j=i;j<=N;j+=i)
    add(j,i);
    while(~scanf("%d%d",&n,&K))
    {
        memset(sum,0,sizeof(sum));
        memset(pre,-1,sizeof(pre));
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
        sort(a,a+n);
        int p=0;
        memset(tr,0,sizeof(tr));
        for(int i=1;i<=N;i++)
        {
            for(int j=hd[i];j!=-1;j=fac[j].ne)
            {
                int k=fac[j].x;
                if(pre[k]!=-1)
                {
                    ret[k]+=read(pre[k]);
                }
                pre[k]=i;
            }
            while(p!=n&&a[p]<=i)
            {
                update(max(1,a[p]-K),1);
                update(a[p]+1,-1);
                p++;
            }
        }
        for(int i=1;i<=N;i++)
        if(pre[i]!=-1)ret[i]+=read(pre[i]);
        int ans=0;
        for(int i=N;i>=1;i--)
        if(ret[i]==n){ans=i;break;}
        cout<<ans<<endl;
    }
    return 0;
}