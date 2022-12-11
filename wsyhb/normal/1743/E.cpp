#include<bits/stdc++.h>
using namespace std;
int p[2],h,s;
long long t[2];
const int max_h=5e3+5;
long long dp[max_h];
int main()
{
	scanf("%d%lld%d%lld%d%d",&p[0],&t[0],&p[1],&t[1],&h,&s);
	dp[0]=0;
	for(int i=1;i<=h;++i)
	{
		long long nxt[2]={t[0],t[1]};
		long long now=0,res=1e18;
		int rem=i;
		while(rem>0)
		{
			int id=(nxt[0]<=nxt[1]?0:1);
			int rem_new=rem-(p[0]+p[1]-s);
			res=min(res,now+nxt[id^1]+dp[max(rem_new,0)]);
			rem-=p[id]-s;
			now+=nxt[id];
			nxt[id^1]-=nxt[id];
			nxt[id]=t[id];
		}
		res=min(res,now);
		dp[i]=res;
	}
	printf("%lld\n",dp[h]);
	return 0;
}