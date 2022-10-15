#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
int n,a[100001][2];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)
	{
		int x;
		scanf("%d",&x);
		if(a[x][0])
		{
			a[x][1]=i;
		}
		else
		{
			a[x][0]=i;
		}
	}
	long long sum=a[1][0]+a[1][1]-2;
	for(int i=2;i<=n;i++)
	{

		sum+=std::min(abs(a[i][0]-a[i-1][0])+abs(a[i][1]-a[i-1][1]),abs(a[i][0]-a[i-1][1])+abs(a[i][1]-a[i-1][0]));
	}
	printf("%lld",sum);
	return 0;
}