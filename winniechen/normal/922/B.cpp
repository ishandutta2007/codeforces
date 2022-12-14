#include <cstdio>
#include <algorithm>
using namespace std;
#define N 2505
int num[N];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if((i^j)<=j)continue;
			if((i^j)>n)continue;
			if((i^j)>=i+j)continue;
			num[i^j]++;
		}
	}
	int ans=0;
	for(int i=3;i<=n;i++)
	{
		ans+=num[i];
	}
	printf("%d\n",ans);
	return 0;
}