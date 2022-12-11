#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[507];
bool f[507][507][507];
int main()
{
    cin>>n>>k;
    memset(f,false,sizeof(f));
    for (int i=1;i<=n;i++) cin>>a[i];
    f[0][0][0]=true;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=k;j++)
            for (int l=0;l<=k;l++)
            {
                f[i][j][l]=f[i-1][j][l];
                if (j>=a[i]) f[i][j][l]=f[i][j][l]|f[i-1][j-a[i]][l];
                if (j>=a[i]&&l>=a[i]) f[i][j][l]=f[i][j][l]|f[i-1][j-a[i]][l-a[i]];
            }
    int ans=0;
    for (int i=0;i<=k;i++)
        if (f[n][k][i]) ++ans;
    cout << ans << endl;
    for (int i=0;i<=k;i++)
        if (f[n][k][i]) cout << i << ' ';
    cout << endl;
}