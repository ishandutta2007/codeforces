#include<bits/stdc++.h>
#define N 100001
#define M 1000000007
using namespace std;
long long t,k,dp[N*2],a[N*2],i,j,x,y;
main()
{
cin>>t>>k;
dp[0]=1;
for (i=0;i<N;i++){dp[i]%=M;dp[i+1]+=dp[i];dp[i+k]+=dp[i];}
for (i=1;i<N;i++)
a[i]=(dp[i]+a[i-1]);
while (t--){
cin>>x>>y;
cout<<(a[y]-a[x-1])%M<<endl;
}
}