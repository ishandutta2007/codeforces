#include <bits/stdc++.h>
using namespace std;
int ans,n,k,a[100005],ones[100005],maxn;
bool asleep[100005];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=k;i++)
	{
		cin>>asleep[i];
		ones[i]=ones[i-1]+a[i]*(!asleep[i]);
		ans+=a[i]*asleep[i];
	}
	for(int i=k+1;i<=n;i++)
	{
		cin>>asleep[i];
		ones[i]=ones[i-1]+a[i]*(!asleep[i])-a[i-k]*(!asleep[i-k]);
		ans+=a[i]*asleep[i];
	}
	for(int i=k;i<=n;i++)
		maxn=max(ones[i],maxn);
	ans+=maxn;
	printf("%d",ans);
	return 0;
}