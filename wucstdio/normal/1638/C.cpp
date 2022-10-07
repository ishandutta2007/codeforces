#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,p[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int maxx=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&p[i]);
			maxx=max(maxx,p[i]);
			if(maxx==i)ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}