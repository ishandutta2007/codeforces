#include <bits/stdc++.h>
#define Maxn 2000007
using namespace std;
int n,m;
int a[Maxn],s[Maxn];
int f[Maxn][3][3];
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        ++s[a[i]];
    }
    memset(f,0,sizeof(f));
    int ans=0;
    for (int i=0;i<=m-2;i++)
    {
        for (int x=0;x<3;x++)
            for (int y=0;y<3;y++)
                for (int k=0;k<3;k++)
                    if (s[i]>=x+y+k&&s[i+1]>=y+k&&s[i+2]>=k)
                    {
                        f[i+1][k][y]=max(f[i+1][k][y],f[i][y][x]+k+(s[i]-x-y-k)/3);
                        if (i==m-2) ans=max(ans,f[i+1][k][y]+(s[i+1]-k-y)/3+(s[i+2]-k)/3);
                    }
    }
    printf("%d\n",ans);
    return 0;
}