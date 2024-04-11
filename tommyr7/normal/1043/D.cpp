#include <bits/stdc++.h>
#define Maxn 200007
using namespace std;
bool flag[Maxn];
int p[11][Maxn],pos[11][Maxn];
int n,m;
long long ans=0LL;
int main()
{
    scanf("%d%d",&n,&m);
    memset(flag,false,sizeof(flag));
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        {
            scanf("%d",&p[i][j]);
            pos[i][p[i][j]]=j;
        }
    for (int r=1;r<=n;r++)
    {
        int i=p[1][r];
        if (!flag[i])
        {
            int j=0;
            bool tmp=true;
            flag[i]=true;
            while (tmp)
            {
                ++j;
                for (int k=1;k<=m;k++)
                    if (pos[k][i]+j>n) tmp=false;
                int now=p[1][pos[1][i]+j];
                for (int k=2;k<=m;k++)
                    if (p[k][pos[k][i]+j]!=now) tmp=false;
                if (tmp) flag[now]=true;
            }
            ans+=(1LL*j*(j+1))/2;
        }
    }
    printf("%lld\n",ans);
    return 0;
}