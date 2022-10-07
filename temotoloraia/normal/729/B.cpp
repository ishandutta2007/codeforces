#include <bits/stdc++.h>
using namespace std;
const int N=1001;
int n,m,mas[N][N];
int a[N][N],b[N][N],c[N][N],d[N][N];
int ans;
int main() {
   cin>>n>>m;
   for (int i=1;i<=n;i++)
   for (int j=1;j<=m;j++)//cin>>mas[i][j];
   scanf("%d",&mas[i][j]);
   for (int i=1;i<=n;i++)
   for (int j=1;j<=m;j++)
   if (mas[i][j]){
   if (a[i][j]==0)for (int l=i+1;l<=n;l++)a[l][j]=1;
   if (c[i][j]==0)for (int l=j+1;l<=m;l++)c[i][l]=1;
   }
   for (int i=n;i>=1;i--)
   for (int j=m;j>=1;j--)
   if (mas[i][j]){
   if (b[i][j]==0)for (int l=i-1;l>=1;l--)b[l][j]=1;
   if (d[i][j]==0)for (int l=j-1;l>=1;l--)d[i][l]=1;
   }
   for (int i=1;i<=n;i++)
   for (int j=1;j<=m;j++)
   if (mas[i][j]==0)
   ans+=a[i][j]+b[i][j]+c[i][j]+d[i][j];
   cout<<ans<<endl;
	return 0;
}