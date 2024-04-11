#include <bits/stdc++.h>
using namespace std;
unsigned long long ans,cnt=1,maxi,n,k,a[200005];
map <unsigned long long,int> Ma;
map <unsigned long long,int>::iterator it;
int main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%llu",&a[i]);
		maxi=max(maxi,a[i]);
	}
	sort(a+1,a+1+n);
	int maxdig=ceil(log10(maxi+1))+1;
	for(int i=1;i<=maxdig;i++)
	{
		long long now=pow(10,i);
		for(int j=cnt;j<=n;j++)
		{
			if(a[j]<now)
			{
				Ma[a[j]%k]++;
				cnt++;
			}
			else break;
		}
		for(int j=1;j<=n;j++)
			if(Ma.find((k-(now*a[j])%k)%k)!=Ma.end())
				ans+=Ma.at((k-(now*a[j])%k)%k);
		Ma.clear();
	}
	for(int i=1;i<=n;i++)
		if((unsigned long long)(pow(10,ceil(log10(a[i]+1.0)))*a[i]+a[i])%k==0) ans--;
	printf("%llu",ans);
	return 0;
}