#include <iostream>
using namespace std;
typedef long long ll;
typedef double db;
ll rez,s,dp[5010][5010],n,a[5010],k,k1,k2,i,j;
#define tr 1000000000
int main() 
{
cin>>n;
for (i=1;i<=n;i++) cin>>a[i];
for (i=0;i<=n;i++)
for (j=0;j<=n;j++)
dp[i][j]=tr;
dp[0][0]=0;
for (i=1;i<=n;i++) 
{
k=-1;s=0;
for (j=i;j<=n;j++)
{
s+=a[j];
while (k<n&&dp[i-1][k+1]<=s) k++;
if (k>=0&&dp[j][k+1]>s) dp[j][k+1]=s;
}
for (k=n-1;k>=0;k--)
if (dp[i][k]>dp[i][k+1]) dp[i][k]=dp[i][k+1];
}
/*for (i=0;i<=n;i++)
{
for (j=0;j<=n;j++)
cout<<dp[i][j]<<" ";
cout<<endl;
}*/
for (k=1;k<=n;k++)
if (dp[n][k]<tr) rez=k;
cout<<n-rez<<endl;
//system("pause");
return 0;
}