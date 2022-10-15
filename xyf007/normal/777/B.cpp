#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
int n,a[1001],b[1001];
int main()
{
	scanf("%d",&n);
	getchar();
	for(int i=1;i<=n;i++)
	{
		char c=getchar();
		a[i]=c-'0';
	}
	getchar();
	for(int i=1;i<=n;i++)
	{
		char c=getchar();
		b[i]=c-'0';
	}
	std::sort(a+1,a+n+1);
	std::sort(b+1,b+n+1);
	int i=1,j=1,ans=0;
	while(i<=n&&j<=n)
	{
		if(a[i]<=b[j])
		{
			i++;
			j++;
		}
		else
		{
			j++;
			ans++;
		}
	}
	printf("%d\n",ans);
	i=1;
	j=1;
	ans=0;
	while(i<=n&&j<=n)
	{
		if(a[i]<b[j])
		{
			i++;
			j++;
			ans++;
		}
		else
		{
			j++;
		}
	}
	printf("%d\n",ans);
	return 0;
}