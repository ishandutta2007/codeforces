#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
long long qpow(long long a,long long b)
{
	long long s=a,ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*s%M;
		s=s*s%M;
		b>>=1;
	}
	return ans;
}
int n,a[300005],i,j;
long long s[300005];
int main()
{
	scanf("%d",&n);
	long long iv=qpow(n,M-2);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(i=1;i<=n;++i)
		s[i]=(s[i-1]+a[i])%M;
	for(i=1;i<=n;++i)
	{
		long long ans=0;
		int k=0;
		for(j=n;j>=0;j-=i,++k)
			ans=(ans+(s[j]-s[max(j-i,0)])*k)%M;
		printf("%lld ",(ans*iv%M+M)%M);
	}
}