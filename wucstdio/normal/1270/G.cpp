#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[1000005],to[1000005],st[1000005],top,last[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			to[i]=i-a[i];
			last[i]=0;
		}
		top=0;
		st[++top]=1;
		last[1]=1;
		int now=1;
		while(!last[to[now]])
		{
			now=to[now];
			st[++top]=now;
			last[now]=top;
		}
		printf("%d\n",top-last[to[now]]+1);
		for(int i=last[to[now]];i<=top;i++)
		  printf("%d ",st[i]);
		printf("\n");
	}
	return 0;
}