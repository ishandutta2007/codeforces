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
ll s,y,j1,j2,rez,p[15],t1,t2,z,x,y1,y2,m,n,i,j,k1,k,dp[10000];
vector <ll> f;
int main()
{
cin>>n>>x>>y1>>y2;
for (i=0;i<=n;i++) dp[i]=-100500;
dp[x]=1;dp[y1]=1;dp[y2]=1;
for (i=0;i<=n;i++)
{
dp[i+x]=max(dp[i]+1,dp[i+x]);
dp[i+y1]=max(dp[i]+1,dp[i+y1]);
dp[i+y2]=max(dp[i]+1,dp[i+y2]);
}
cout<<dp[n]<<endl;
return 0;
}