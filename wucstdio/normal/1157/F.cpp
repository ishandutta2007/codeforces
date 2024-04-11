#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,num[200005],sum[200005],maxs,maxnum;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		num[x]++;
	}
	n=200000;
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+num[i];
	for(int i=1;i<=n;i++)
	{
		if(num[i]==0)continue;
		int x=i+1;
		while(num[x]>=2)x++;
		if(num[x]==1)x++;
		if(sum[x-1]-sum[i-1]>maxnum)
		{
			maxnum=sum[x-1]-sum[i-1];
			maxs=i;
		}
	}
	printf("%d\n",maxnum);
	printf("%d ",maxs);
	num[maxs]--;
	int x=maxs+1;
	while(num[x]>=2)
	{
		num[x]--;
		printf("%d ",x);
		x++;
	}
	if(num[x]==1)
	{
		num[x]--;
		printf("%d ",x);
	}
	while(x!=maxs)
	{
		x--;
		while(num[x])
		{
			printf("%d ",x);
			num[x]--;
		}
	}
	printf("\n");
	return 0;
}