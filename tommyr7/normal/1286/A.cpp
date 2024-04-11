#include <bits/stdc++.h>
#define Maxn 107
using namespace std;
int n;
int p[Maxn];
int f[Maxn][Maxn][107][2];
int cnt1=0,cnt2=0;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        if (i%2==0) ++cnt2; else ++cnt1;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
        if (p[i]!=0)
        {
            if (p[i]%2==1) --cnt1; else --cnt2;
        }
    }
    memset(f,0,sizeof(f));
    for (int i=0;i<=n;i++)
        for (int j=0;j<=n;j++)
            for (int k=0;k<=n;k++)
                f[i][j][k][0]=f[i][j][k][1]=100007;
    f[cnt1][cnt2][0][0]=f[cnt1][cnt2][0][1]=0;
    for (int i=1;i<=n;i++)
        for (int a=0;a<=cnt1;a++)
            for (int b=0;b<=cnt2;b++)
            {
                if (p[i]!=0)
                {
                    if (p[i]%2==0) f[a][b][i][0]=min(f[a][b][i-1][0],f[a][b][i-1][1]+1);
                    else f[a][b][i][1]=min(f[a][b][i-1][1],f[a][b][i-1][0]+1);
                }
                else
                {
                    f[a][b][i][0]=min(f[a][b][i][0],f[a][b+1][i-1][0]);
                    f[a][b][i][0]=min(f[a][b][i][0],f[a][b+1][i-1][1]+1);
                    f[a][b][i][1]=min(f[a][b][i][1],f[a+1][b][i-1][0]+1);
                    f[a][b][i][1]=min(f[a][b][i][1],f[a+1][b][i-1][1]);
                }
            }
    printf("%d\n",min(f[0][0][n][0],f[0][0][n][1]));
    return 0;
}