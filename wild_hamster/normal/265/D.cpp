#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll max1,d[100005],a[100005],dp[100005],i,j,m,n,k;
vector <ll> f[100005];
//bool prime[100005](false);
int main()
{
cin>>n;
for (i=0;i<n;i++) cin>>a[i];
for (i=0;i<=100000;i++) {dp[i]=0;d[i]=0;}
for (i=2;i<=100000;i++)
for (j=i;j<=100000;j+=i)
{/*f[i].push_back(j);*/f[j].push_back(i);}
/*for (i=99997;i<=99997;i++)
{
cout<<endl;
for (j=0;j<f[i].size();j++)
cout<<f[i][j]<<" ";
}*/
for (i=0;i<n;i++)
{
max1=-1;
for (j=0;j<f[a[i]].size();j++)
if (d[f[a[i]][j]]>max1) max1=d[f[a[i]][j]];
for (j=0;j<f[a[i]].size();j++)
d[f[a[i]][j]]=max1+1;
dp[i]=max1+1;
/*for (j=0;j<=10;j++)
cout<<d[j]<<" ";
cout<<endl;*/
}
max1=0;
for (i=0;i<=100000;i++)
if (dp[i]>max1) max1=dp[i];
cout<<max((ll)1,max1)<<endl;
return 0;
}