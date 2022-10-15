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
	int ans=0;
	for(int i=n;i>=1;i--)
	{
		if(a[1]!=a[i])
		{
			ans=std::max(ans,i-1);
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[n])
		{
			ans=std::max(ans,n-i);
		}
	}
	printf("%d",ans);
	return 0;
}