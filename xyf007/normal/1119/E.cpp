#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
int n,a[300001];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	long long sum=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		long long temp=std::min(sum,(long long)a[i]/2);
		ans+=temp;
		sum-=temp;
		a[i]-=temp*2;
		if(a[i]>=3)
		{
			ans+=a[i]/3;
			a[i]%=3;
		}
		sum+=a[i];
	}
	printf("%lld",ans);
	return 0;
}