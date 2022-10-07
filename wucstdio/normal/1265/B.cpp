#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,p[200005],pos[200005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&p[i]);
			pos[p[i]]=i;
		}
		int maxx=0,minn=n+1;
		for(int i=1;i<=n;i++)
		{
			maxx=max(maxx,pos[i]);
			minn=min(minn,pos[i]);
			if(maxx-minn+1==i)printf("1");
			else printf("0");
		}
		printf("\n");
	}
	return 0;
}