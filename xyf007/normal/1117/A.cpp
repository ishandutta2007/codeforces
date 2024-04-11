#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[100001]; 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int mx=-1,ans=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>mx)
		{
			mx=a[i];
			ans=1;
		}
		if(a[i]==mx)
		{
			if(a[i-1]==mx)
			{
				sum++;
			}
			else
			{
				sum=1;
			}
		}
		if(a[i]<mx)
		{
			sum=0;
			continue;
		}
		if(ans<sum)
		{
			ans=sum;
		}
	}
	printf("%d",ans);
	return 0;
}
//