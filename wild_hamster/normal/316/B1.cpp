#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
using namespace std;
typedef long long ll;
typedef double db;
//map <ll,ll> a,b,c;
vector <ll> f,f2,dp[2000];
ll x,a[2000],b[2000],n1,i1,c[2000500],d,s,t,m,i,j,k,rez,n,k1,k2,k3,k4,k5;
string s1;
void dfs(ll t)
{
if (t==x) k3=k2;
if (a[t]==0) return;
else {k2++;dfs(a[t]);}
}
int main()
{
cin>>n>>x;
j=0;
for (i=0;i<2000;i++) {a[i]=0;b[i]=0;}
for (i=1;i<=n;i++)
{
cin>>k1;
if (k1) a[k1]=i; else f.push_back(i);
}
f2.push_back(0);
for (i=0;i<f.size();i++)
{
k2=1;k3=0;
dfs(f[i]);
if (k3) {rez=k3;t=k2;} else
f2.push_back(k2);
}
//cout<<rez<<endl;
/*for (i=0;i<f2.size();i++)
dp[0].push_back(f2[i]);
for (i=0;i<=n;i++)
if (dp[i].size())
{
for (j=0;j<dp[i].size();j++)
if (!dp[i+dp[i][j]].size())
{
for (k=0;k<dp[i].size();k++)
if (k!=j) dp[i+dp[i][j]].push_back(dp[i][k]); else
dp[i+dp[i][j]].push_back(0);
}
}
for (i=0;i<=n-t;i++)
if (dp[i].size()) cout<<i+rez<<endl;*/
sort(f2.begin(),f2.end());
b[0]=1;
for (i=0;i<f2.size();i++)
{
for (j=0;j<n;j++)
if (b[j]==1&&b[f2[i]+j]==0) b[f2[i]+j]=2;
for (j=0;j<n;j++)
if (b[j]==2) b[j]=1;
}
for (i=0;i<=n;i++)
if (b[i]) cout<<i+rez<<endl;
return 0;
}