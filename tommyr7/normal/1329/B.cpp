#include <bits/stdc++.h>
using namespace std;
int T,n,modp;
int f[31][31];
void solve()
{
    scanf("%d%d",&n,&modp);
    memset(f,0,sizeof(f));
    int ans=0;
    for (int i=0;i<=30;i++)
    {
        f[1][i]=min(n,(1<<i)-1);
        if (i!=0) f[1][i]-=((1<<(i-1))-1);
        f[1][i]=max(0,f[1][i]);
        f[1][i]%=modp;
        ans=(ans+f[1][i])%modp;
    }
    for (int i=2;i<=30;i++)
        for (int j=0;j<=30;j++)
        {
            f[i][j]=0;
            for (int k=0;k<j;k++)
                f[i][j]=(f[i][j]+1LL*f[i-1][k]*f[1][j])%modp;
            ans=(ans+f[i][j])%modp;
        }
    printf("%d\n",ans);
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}