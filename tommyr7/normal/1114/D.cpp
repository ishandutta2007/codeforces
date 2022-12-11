#include <bits/stdc++.h>
#define Maxn 5007
using namespace std;
int f[Maxn][Maxn];
int n,m=1;
int a[Maxn];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=2;i<=n;i++)
        if (a[i]!=a[m]) a[++m]=a[i];
    n=m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            f[i][j]=200007;
    for (int i=1;i<=n;i++)
        f[i][i]=0;
    for (int i=1;i<n;i++)
        f[i][i+1]=1;
    for (int len=2;len<n;len++)
        for (int i=1;i<=n-len;i++)
        {
            int j=i+len;
            f[i][j]=1;
            if (a[i]==a[j]) f[i][j]+=f[i+1][j-1]; else f[i][j]+=min(f[i+1][j],f[i][j-1]);
        }
    printf("%d\n",f[1][n]);
    return 0;
}