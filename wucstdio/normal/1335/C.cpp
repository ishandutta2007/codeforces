#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,cnt[200005],num;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)cnt[i]=0;
		num=0;
		int maxx=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			if(!cnt[x])num++;
			cnt[x]++;
			maxx=max(maxx,cnt[x]);
		}
		if(num!=maxx)printf("%d\n",min(num,maxx));
		else printf("%d\n",num-1);
	}
	return 0;
}