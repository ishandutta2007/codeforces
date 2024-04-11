#include <bits/stdc++.h>
#define modp 1000000007
#define Maxn 107
using namespace std;
long long n;
int m;
int ans[Maxn],now[Maxn][Maxn],t[Maxn][Maxn],p[Maxn];
int main()
{
    scanf("%lld%d",&n,&m);
    ans[1]=1;
    for (int i=1;i<m;i++)
        now[i][i+1]=1;
    now[m][1]=1;
    now[1][1]=1;
    while (n>0)
    {
        if (n%2==1)
        {
            memset(p,0,sizeof(p));
            for (int i=1;i<=m;i++)
                for (int j=1;j<=m;j++)
                    p[j]=(p[j]+1LL*ans[i]*now[i][j])%modp;
            for (int i=1;i<=m;i++)
                ans[i]=p[i];
        }
        n/=2;
        memset(t,0,sizeof(t));
        for (int i=1;i<=m;i++)
            for (int j=1;j<=m;j++)
                for (int k=1;k<=m;k++)
                    t[i][j]=(t[i][j]+1LL*now[i][k]*now[k][j])%modp;
        for (int i=1;i<=m;i++)
            for (int j=1;j<=m;j++)
                now[i][j]=t[i][j];
    }
    printf("%d\n",ans[1]);
    return 0;
}