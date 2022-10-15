#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
int n,a[101];
int main()
{
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n;i++)
	{
		if(a[i]==1)
		{
			if(a[i+1]==2)
			{
				ans+=3;
				if(i>1&&a[i-1]==3)
				{
					ans--;
				}
			}
			if(a[i+1]==3)
			{
				ans+=4;
			}
		}
		if(a[i]==2)
		{
			if(a[i+1]==1)
			{
				ans+=3;
			}
			if(a[i+1]==3)
			{
				printf("Infinite");
				return 0;
			}
		}
		if(a[i]==3)
		{
			if(a[i+1]==1)
			{
				ans+=4;
			}
			if(a[i+1]==2)
			{
				printf("Infinite");
				return 0;
			}
		}
	}
	printf("Finite\n%d",ans);
	return 0;
}