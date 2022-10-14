#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <time.h>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
#define pb push_back
ll k1,k2,k3,t,s,y,j1,j2,rez,z,b[10500],dp[10500][64],a[3][10500],t1,t2,x,y1,y2,m,n,i,j,k;
vector <ll > f[4];
ll dfs()
{
        ll i,j,k;
for (i=0;i<=n;i++)
for (j=0;j<8;j++)
dp[i][j]=0;
for (i=0;i<=n;i++) b[i]=a[0][i]*4+a[1][i]*2+a[2][i]*1;
for (i=0;i<=n;i++)
for (j=0;j<8;j++)
if ((j&b[i])==0)
{
if (i==0&&j==0) dp[i][j+b[i]]=1;
else
{
k=j+b[i];
if (j==0) dp[i][k]=dp[i-1][7];
if (j==1) dp[i][k]=dp[i-1][6];
if (j==2) dp[i][k]=dp[i-1][5];
if (j==3) dp[i][k]=(dp[i-1][4]+dp[i][b[i]])%tr;
if (j==4) dp[i][k]=dp[i-1][3];
if (j==5) dp[i][k]=dp[i-1][2];
if (j==6) dp[i][k]=(dp[i-1][1]+dp[i][b[i]])%tr;
if (j==7) dp[i][k]=(dp[i-1][0]+dp[i][1+b[i]]+dp[i][4+b[i]])%tr;
}
}
return dp[n][0];
}
int main()
{
cin>>n;
for (i=0;i<3;i++)
for (j=0;j<n;j++)
{
char s;
cin>>s;
if (s=='O') {x=i;y=j;a[i][j]=1;} 
if (s=='X') a[i][j]=1;
if (s=='.') a[i][j]=0;
}
if (x>1&&a[x-1][y]==0&&a[x-2][y]==0)
{
f[0].pb(x-1);f[1].pb(y);f[2].pb(x-2);f[3].pb(y);
}

if (x==0&&a[x+1][y]==0&&a[x+2][y]==0)
{
f[0].pb(x+1);f[1].pb(y);f[2].pb(x+2);f[3].pb(y);
}

if (y>1&&a[x][y-1]==0&&a[x][y-2]==0)
{
f[0].pb(x);f[1].pb(y-1);f[2].pb(x);f[3].pb(y-2);
}

if (y<n-2&&a[x][y+1]==0&&a[x][y+2]==0)
{
f[0].pb(x);f[1].pb(y+1);f[2].pb(x);f[3].pb(y+2);
}
//cout<<f[0].size()<<endl;
if (f[0].size()==1)
{
for (i=0;i<2;i++)
a[f[i*2][0]][f[i*2+1][0]]=1;
cout<<dfs()<<endl;
} else
if (f[0].size()==2)
{
ll k1=0;
for (j=0;j<2;j++)
{
for (i=0;i<2;i++)
a[f[i*2][j]][f[i*2+1][j]]=1;
k1+=dfs();
for (i=0;i<2;i++)
a[f[i*2][j]][f[i*2+1][j]]=0;
}
for (j=0;j<2;j++)
for (i=0;i<2;i++)
a[f[i*2][j]][f[i*2+1][j]]=1;
k1-=dfs();
cout<<(k1+tr*(ll)100)%tr<<endl;
} else
if (f[0].size()==0)
cout<<0<<endl;
else
{
ll k1=0,k2;
for (j=0;j<3;j++)
for (i=0;i<2;i++)
a[f[i*2][j]][f[i*2+1][j]]=1;
k1+=dfs();
for (j=0;j<3;j++)
for (i=0;i<2;i++)
a[f[i*2][j]][f[i*2+1][j]]=0;
for (j=0;j<3;j++)
{
for (i=0;i<2;i++)
a[f[i*2][j]][f[i*2+1][j]]=1;
k1+=dfs();
for (i=0;i<2;i++)
a[f[i*2][j]][f[i*2+1][j]]=0;
}
for (j=0;j<=2;j++)
for (k=j+1;k<=2;k++)
{
for (i=0;i<2;i++)
a[f[i*2][k]][f[i*2+1][k]]=1;
for (i=0;i<2;i++)
a[f[i*2][j]][f[i*2+1][j]]=1;
k1-=dfs();
for (i=0;i<2;i++)
a[f[i*2][k]][f[i*2+1][k]]=0;
for (i=0;i<2;i++)
a[f[i*2][j]][f[i*2+1][j]]=0;
}
cout<<(k1+tr*(ll)100)%tr<<endl;
}
return 0;
}