#include <bits/stdc++.h>
using namespace std;
#define Maxn 100007
int T,n,a,b;
char ch[Maxn];
int f[Maxn][2];
void solve()
{
    scanf("%d%d",&a,&b);
    scanf("%s",ch+1);
    n=strlen(ch+1);
    f[0][0]=0;
    f[0][1]=0;
    for (int i=1;i<=n;i++)
        if (ch[i]=='1')
        {
            f[i][0]=min(f[i-1][1],f[i-1][0])+a;
            f[i][1]=min(f[i-1][1],f[i-1][0]);
        } else
        {
            f[i][0]=min(f[i-1][1]+a,f[i-1][0]);
            f[i][1]=min(f[i-1][1],f[i-1][0])+b;
        }
    printf("%d\n",min(f[n][0],f[n][1]+a));
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}