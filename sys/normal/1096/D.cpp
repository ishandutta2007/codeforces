#include <bits/stdc++.h>
using namespace std;
const int Maxn=100005;
int n,a[Maxn];
long long dp[5]; 
string str;
int main()
{
//	freopen("CF1096D.in","r",stdin);
	scanf("%d",&n);
	cin>>str;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		if(str[i-1]=='h') dp[1]+=a[i];
		if(str[i-1]=='a') dp[2]=min(dp[2]+a[i],dp[1]);
		if(str[i-1]=='r') dp[3]=min(dp[3]+a[i],dp[2]);
		if(str[i-1]=='d') dp[4]=min(dp[4]+a[i],dp[3]);
	}
	printf("%lld",dp[4]);
	return 0;
}