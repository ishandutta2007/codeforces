#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,l[100005],ans[100005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d",&l[i]);
	long long s=0;
	for(int i=1;i<=m;i++)
	{
		s+=l[i];
		if(l[i]>n-i+1)
		{
			printf("-1\n");
			return 0;
		}
	}
	if(s<n)
	{
		printf("-1\n");
		return 0;
	}
	int now=n-l[m]+1;
	for(int i=m;i>=1;i--)
	{
		ans[i]=now;
		now-=l[i-1];
		now=max(now,i-1);
		now=min(now,n-l[i-1]+1);
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	printf("\n");
	return 0;
}