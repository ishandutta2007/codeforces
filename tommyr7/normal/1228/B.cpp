#include <bits/stdc++.h>
#define modp 1000000007
#define Maxn 1007
int s[Maxn][Maxn];
int n,m;
int a[Maxn],b[Maxn];
bool flag=true;
int main()
{
    scanf("%d%d",&n,&m);
    memset(s,-1,sizeof(s));
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        for (int j=1;j<=a[i];j++)
        {
            if (s[i][j]==0) flag=false;
            s[i][j]=1;
        }
        if (s[i][a[i]+1]==1) flag=false;
        s[i][a[i]+1]=0;
    }
    for (int i=1;i<=m;i++)
    {
        scanf("%d",&b[i]);
        for (int j=1;j<=b[i];j++)
        {
            if (s[j][i]==0) flag=false;
            s[j][i]=1;
        }
        if (s[b[i]+1][i]==1) flag=false;
        s[b[i]+1][i]=0;
    }
    if (!flag) printf("%d\n",0);
    else
    {
        int ans=1;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (s[i][j]==-1) ans=(2LL*ans)%modp;
        printf("%d\n",ans);
    }
    return 0;
}