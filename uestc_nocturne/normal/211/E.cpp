#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const int V=5100;
struct Edge{int num,ne;}e[V];
int p[V],K;
void add(int x,int y)
{
    e[K].num=y;e[K].ne=p[x];p[x]=K++;
}
int set[V];
int find(int x)
{
    if(x!=set[x])set[x]=find(set[x]);
    return set[x];
}
void U(int x,int y)
{
    int p=find(x);
    if(p==find(y))return;
    set[p]=y;
}
int x[V],y[V],n;
int can[V],dp[V],nu[V];
int main()
{
    while(~scanf("%d",&n))
    {
        memset(can,0,sizeof(can));
        for(int i=0;i<n-1;i++)
        scanf("%d%d",&x[i],&y[i]);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)set[j]=j,nu[j]=0;
            for(int j=0;j<n-1;j++)
            {
                if(x[j]==i||y[j]==i)continue;
                U(x[j],y[j]);
            }
            for(int j=1;j<=n;j++)
            if(j!=i)nu[find(j)]++;
            for(int j=1;j<=n;j++)if(nu[j]==n-1)continue;
            memset(dp,0,sizeof(dp));
            dp[0]=1;
            for(int j=1;j<=n;j++)
            {
                if(nu[j]==0)continue;
                for(int k=n-1;k>=nu[j];k--)
                if(dp[k-nu[j]])dp[k]=1;
            }
            for(int j=1;j<n-1;j++)if(dp[j])can[j]=1;
        }
        int ct=0;
        for(int i=1;i<n;i++)
        if(can[i])ct++;
        printf("%d\n",ct);
        for(int i=1;i<n-1;i++)
        if(can[i])printf("%d %d\n",i,n-i-1);
    }
}