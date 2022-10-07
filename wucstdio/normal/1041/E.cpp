#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,num[1005],now,rest,ans[1005],right;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if(u!=n&&v!=n)
		{
			printf("NO\n");
			return 0;
		}
		num[u]++;
	}
	ans[1]=n;
	now=2;
	right=1;
	for(int i=n-1;i>=1;i--)
	{
		if(num[i]==0&&rest==0)
		{
			printf("NO\n");
			return 0;
		}
		if(num[i]==0)
		{
			while(ans[now])now++;
			ans[now]=i;
			now++;
			rest--;
		}
		else
		{
			right+=num[i];
			ans[right]=i;
			rest+=num[i]-1;
		}
	}
	printf("YES\n");
	for(int i=2;i<=n;i++)
	  printf("%d %d\n",ans[i-1],ans[i]);
	return 0;
}