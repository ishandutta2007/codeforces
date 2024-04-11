#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int ans=0;
	scanf("%d",&n);
	int a[20002];
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		ans+=a[i];
	}
	vector<int> divs;
	for(int i=1;i<n/2;i++)
	{
		if(n%i==0) divs.push_back(i);
	}
	for(int i=0;i<divs.size();i++)
	{
		int d=divs[i];
		int sum[20002];
		memset(sum,0,sizeof(sum));
		for(int j=0;j<n;j++)
		{
			sum[j%d]+=a[j];
		}
		for(int j=0;j<d;j++)
		{
			ans=max(ans,sum[j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}