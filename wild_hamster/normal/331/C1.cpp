#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <cmath>
#define tr 1000000007
#define eps 1e+12
#define maxn 20000000
using namespace std;
typedef long long ll;
typedef double db;
//map <ll,ll> a,b,c;
map <ll,ll> f1,f2;
ll b[7],dp[2000000],m,i,j,n;
vector <ll> f,g[2];
int main()
{
cin>>n;
dp[n]=0;
for (i=0;i<n;i++) dp[i]=(ll)1e+12;
for (i=n;i>=1;i--)
{
b[0]=(i/1000000)%10;
b[1]=(i/100000)%10;
b[2]=(i/10000)%10;
b[3]=(i/1000)%10;
b[4]=(i/100)%10;
b[5]=(i/10)%10;
b[6]=i%10;
for (j=0;j<7;j++)
dp[i-b[j]]=min(dp[i-b[j]],dp[i]+1);
}
cout<<dp[0]<<endl;
return 0;
}