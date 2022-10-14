#include <bits/stdc++.h>
#define SZ 500005
using namespace std;

int n,k,d,a[SZ],b[SZ],dp[SZ];
int get(int l,int r)
{
	return b[r]-(l>0?b[l-1]:0);
}
int main()
{
	scanf("%d%d%d",&n,&k,&d);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	dp[0]=1;b[0]=1;
	for(int i=1,j=1;i<=n;i++)
	{
		while(a[i]-a[j]>d) j++;
		if(i-j+1>=k) dp[i]=(get(j-1,i-k)>0?1:0);
		b[i]=b[i-1]+dp[i];
	}
	puts(dp[n]?"YES":"NO");
	return 0;
}