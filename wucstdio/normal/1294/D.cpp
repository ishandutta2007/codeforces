#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int q,x,ans,cnt[400005];
int main()
{
	scanf("%d%d",&q,&x);
	while(q--)
	{
		int v;
		scanf("%d",&v);
		cnt[v%x]++;
		while(cnt[ans%x])
		{
			cnt[ans%x]--;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}