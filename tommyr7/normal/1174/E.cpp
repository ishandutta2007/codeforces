#include <bits/stdc++.h>
#define Maxn 1000007
#define modp 1000000007
using namespace std;
int n;
int f[Maxn][21][2];
int calc(int x,int y)
{
    int res=n;
    if (y==1) res/=3;
    return (res/(1<<x));
}
int main()
{
    scanf("%d",&n);
    memset(f,0,sizeof(f));
    int now=0;
    while ((1<<now)<=n) ++now;
    --now;
    f[1][now][0]=1;
    if (now>=1&&(3*(1<<(now-1))<=n)) f[1][now-1][1]=1;
    for (int i=1;i<n;i++)
        for (int x=0;x<21;x++)
            for (int y=0;y<2;y++)
                if (f[i][x][y])
                {
                    f[i+1][x][y]=(f[i+1][x][y]+1LL*f[i][x][y]*(calc(x,y)-i))%modp;
                    if (x>0) f[i+1][x-1][y]=(f[i+1][x-1][y]+1LL*f[i][x][y]*(calc(x-1,y)-calc(x,y)))%modp;
                    if (y>0) f[i+1][x][y-1]=(f[i+1][x][y-1]+1LL*f[i][x][y]*(calc(x,y-1)-calc(x,y)))%modp;
                }
    printf("%d\n",(f[n][0][0]+modp)%modp);
    return 0;
}