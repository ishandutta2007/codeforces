#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[1001];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int ans=2e9;
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		for(int j=1;j<=n;j++)
		{
			sum+=2*a[j]*(abs(j-i)+j+i-2);
		}
		if(sum<ans)
		{
			ans=sum;
		}
	}
	printf("%d",ans);
	return 0;
}
//