#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[300005],last[300005],v[300005],ans[300005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)last[i]=v[i]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			v[a[i]]=max(v[a[i]],i-last[a[i]]);
			last[a[i]]=i;
		}
		for(int i=1;i<=n;i++)v[i]=max(v[i],n+1-last[i]);
		for(int i=1;i<=n;i++)ans[i]=n+1;
		for(int i=1;i<=n;i++)ans[v[i]]=min(ans[v[i]],i);
		for(int i=2;i<=n;i++)ans[i]=min(ans[i],ans[i-1]);
		for(int i=1;i<=n;i++)
		{
			if(ans[i]!=n+1)printf("%d ",ans[i]);
			else printf("-1 ");
		}
		printf("\n");
	}
	return 0;
}