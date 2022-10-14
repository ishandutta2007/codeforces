#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <cmath>
#define tr 1000000007
using namespace std;
typedef long long ll;
typedef double db;
ll k,k1,k2,i,n,m,c[105][105],dp[105][10105],a[105],b[105],j,azaza,min1,z1,x,z2,yw,xb,yb,z;
ll binpow(ll a, ll m)
{
if (m==0) return 1;
if (m%2==1) return (a*binpow(a,m-1))%tr; else
return (binpow((a*a)%tr,m/2))%tr;
} 
ll ob(ll k)
{
return binpow(k,tr-2);
}
int main()
{
cin>>n>>m>>k1;
a[1]=a[0]=1;
for (i=2;i<=n;i++)
a[i]=(i*a[i-1])%tr;
for (i=0;i<=n;i++)
b[i]=(((a[n]*ob(a[n-i]))%tr)*ob(a[i]))%tr;
for (i=0;i<=n;i++)
for (j=1;j<=n;j++)
c[j][i]=binpow(b[i],(m-j)/n+1);
for (i=0;i<105;i++)
for (j=0;j<10005;j++)
dp[i][j]=0;
for (i=0;i<=n;i++)
dp[1][i]=c[1][i];
//cout<<dp[1][i]<<" ";
for (i=2;i<=n;i++)
for (j=0;j<=k1;j++)
for (k=0;k<=n;k++)
{
dp[i][j]=(dp[i][j]+dp[i-1][j-k]*c[i][k])%tr;
//cout<<dp[i][j]<<endl;
}
cout<<dp[n][k1];
return 0;
}