#include <stdio.h>
int min(int a, int b){ return a>b?b:a;}
const int L=30;
int cnt[L];
int main()
{
	int n,q,i,x,j;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		for(j=0;j<L;j++) if(x==(1<<j)) cnt[j]++;
	}
	while(q--)
	{
		scanf("%i",&x);
		int ans=0,need=0;
		for(j=L-1;~j;j--)
		{
			need+=(x>>j)&1;
			ans+=min(need,cnt[j]);
			need-=min(need,cnt[j]);
			need*=2;
		}
		if(need) printf("-1\n");
		else printf("%i\n",ans);
	}
	return 0;
}