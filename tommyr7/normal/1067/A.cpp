#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#define Maxn 200007
#define modp 998244353
int n;
int a[Maxn];
int f[2][207][3],s[2][207][3];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    memset(f,0,sizeof(f));
    memset(s,0,sizeof(s));
    for (int i=0;i<=200;i++)
        s[0][i][0]=1;
    for (int i=1;i<=n;i++)
    {
        int now=i&1,pre=1-now;
        for (int i=0;i<=200;i++)
            for (int j=0;j<=2;j++)
                f[now][i][j]=0,s[now][i][j]=0;
        for (int j=1;j<=200;j++)
        {
            if (a[i]==-1||a[i]==j)
            {
                f[now][j][0]=(f[now][j][0]+s[pre][j-1][0])%modp;
                f[now][j][0]=(f[now][j][0]+s[pre][j-1][1])%modp;
                f[now][j][0]=(f[now][j][0]+s[pre][j-1][2])%modp;
                f[now][j][1]=(f[now][j][1]+f[pre][j][0])%modp;
                f[now][j][1]=(f[now][j][1]+f[pre][j][1])%modp;
                f[now][j][1]=(f[now][j][1]+f[pre][j][2])%modp;
                f[now][j][2]=(f[now][j][2]+s[pre][200][1])%modp;
                f[now][j][2]=(f[now][j][2]+modp-s[pre][j][1])%modp;
                f[now][j][2]=(f[now][j][2]+s[pre][200][2])%modp;
                f[now][j][2]=(f[now][j][2]+modp-s[pre][j][2])%modp;
                if (i==2) f[now][j][2]=0;
            }
            s[now][j][0]=(s[now][j-1][0]+f[now][j][0])%modp;
            s[now][j][1]=(s[now][j-1][1]+f[now][j][1])%modp;
            s[now][j][2]=(s[now][j-1][2]+f[now][j][2])%modp;
        }
    }
    int ans=0;
    ans=(ans+s[n&1][200][1])%modp;
    ans=(ans+s[n&1][200][2])%modp;
    printf("%d\n",ans);
    return 0;
}