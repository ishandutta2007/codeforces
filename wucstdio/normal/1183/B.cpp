#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,k,maxx,minn;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		maxx=0,minn=2147483647;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			int v;
			scanf("%d",&v);
			maxx=max(maxx,v);
			minn=min(minn,v);
		}
		if(maxx-minn<=2*k)printf("%d\n",minn+k);
		else printf("-1\n");
	}
	return 0;
}