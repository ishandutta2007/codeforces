#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
int n,r,a[2001],right;
int main()
{
	scanf("%d%d",&n,&r);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int ans=0;
	for(int i=1;i<=n;)
	{
		int temp=-1;
		for(int j=i+r-1;j>right;j--)
		{
			if(a[j])
			{
				temp=j;
				break;
			}
		}
		if(temp==-1)
		{
			printf("-1");
			return 0;
		}
		right=temp;
		ans++;
		i=temp+r;
	}
	printf("%d",ans);
	return 0;
}
//