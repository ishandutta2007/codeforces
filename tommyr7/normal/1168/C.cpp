#include <bits/stdc++.h>
using namespace std;
#define Maxn 300007
int n,q;
int a[Maxn];
int nxt[Maxn][23],f[Maxn][23];
int main()
{
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int j=0;j<=20;j++)
    {
        nxt[n][j]=n+1;
        for (int i=n-1;i;i--)
        {
            nxt[i][j]=nxt[i+1][j];
            if (a[i+1]&(1<<j)) nxt[i][j]=i+1;
        }
    }
    for (int k=0;k<=20;k++)
        f[n+1][k]=n+1;
    for (int i=n;i;i--)
        for (int j=0;j<=20;j++)
            if (a[i]&(1<<j)) f[i][j]=i; else 
            {
                f[i][j]=n+1;
                for (int k=0;k<=20;k++)
                    if (a[i]&(1<<k)) f[i][j]=min(f[i][j],f[nxt[i][k]][j]);
            }
    while (q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        bool flag=false;
        for (int k=0;k<=20;k++)
            if ((a[y]&(1<<k))&&(f[x][k]<=y)) flag=true;
        if (flag) printf("Shi\n"); else printf("Fou\n");
    }
    return 0;
}