#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,k,a[200005],b[200005],ta,tb;
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&ta,&tb,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	if(k>=min(n,m))
	{
		printf("-1\n");
		return 0;
	}
	int now=1,ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i-1>k)break;
		while(a[i]+ta>b[now]&&now<=m)now++;
		int rest=k-(i-1);
		if(now+rest>m)
		{
			ans=-1;
			break;
		}
		else ans=max(ans,b[now+rest]+tb);
	}
	printf("%d\n",ans);
	return 0;
}