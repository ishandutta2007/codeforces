#include <bits/stdc++.h>
#define Maxn 507
using namespace std;
int n,m;
int a[Maxn][Maxn],b[Maxn][Maxn];
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            scanf("%d",&b[i][j]);
            if (a[i][j]==b[i][j]) a[i][j]=0; else a[i][j]=1;
        }
    for (int i=n;i>1;i--)
        for (int j=m;j>1;j--)
            if (a[i][j]!=0)
            {
                a[i][j]=1-a[i][j];
                a[1][j]=1-a[1][j];
                a[i][1]=1-a[i][1];
                a[1][1]=1-a[1][1];
            }
    bool check=true;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]!=0) check=false;
    if (check) printf("Yes\n"); else printf("No\n");
    return 0;
}