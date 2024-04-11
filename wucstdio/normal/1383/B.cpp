#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,cnt[32];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)
		{
			int v;
			scanf("%d",&v);
			for(int j=0;j<31;j++)
			  if((1<<j)&v)cnt[j]++;
		}
		int cur=30;
		while(cur>=0&&!(cnt[cur]&1))cur--;
		if(cur==-1)printf("DRAW\n");
		else
		{
			cnt[cur]/=2;
			if(cnt[cur]&1)
			{
				if(n&1)printf("LOSE\n");
				else printf("WIN\n");
			}
			else printf("WIN\n");
		}
	}
	return 0;
}