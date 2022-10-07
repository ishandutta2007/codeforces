#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,x,sum[100005],_cnt[200005],*cnt=_cnt+100000;
char s[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(_cnt,0,sizeof(_cnt));
		scanf("%d%d",&n,&x);
		scanf("%s",s+1);
		sum[0]=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')sum[i]=sum[i-1]+1;
			else sum[i]=sum[i-1]-1;
		}
		for(int i=0;i<n;i++)
		  cnt[sum[i]]++;
		if(sum[n]==0)
		{
			if(x>=-100000&&x<=100000&&cnt[x])
			{
				printf("-1\n");
				continue;
			}
			else
			{
				printf("0\n");
				continue;
			}
		}
		if(sum[n]>0&&x<-100000)
		{
			printf("0\n");
			continue;
		}
		if(sum[n]<0&&x>100000)
		{
			printf("0\n");
			continue;
		}
		if(x>100000)x-=(x-100001)/sum[n]*sum[n]+sum[n];
		if(x<-100000)x-=(-100001-x)/(-sum[n])*sum[n]+sum[n];
		long long ans=0;
		while(x>=-100000&&x<=100000)
		{
			ans+=cnt[x];
			x-=sum[n];
		}
		printf("%lld\n",ans);
	}
	return 0;
}