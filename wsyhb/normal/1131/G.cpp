#include<bits/stdc++.h>
using namespace std;
const int max_n=25e4+5;
int k[max_n];
vector<int> a[max_n],c[max_n];
const int max_m=1e7+5;
int h[max_m];
long long cost[max_m];
int l[max_m],r[max_m],st[max_m],tp;
long long dp[max_m];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",k+i);
		a[i].resize(k[i]);
		for(int j=0;j<k[i];++j)
			scanf("%d",&a[i][j]);
		c[i].resize(k[i]);
		for(int j=0;j<k[i];++j)
			scanf("%d",&c[i][j]);
	}
	int q;
	scanf("%d",&q);
	int cnt=0;
	while(q--)
	{
		int id,mul;
		scanf("%d%d",&id,&mul);
		for(int i=0;i<k[id];++i)
		{
			h[++cnt]=a[id][i];
			cost[cnt]=1ll*c[id][i]*mul;
		}
	}
	assert(cnt==m);
	for(int i=1;i<=m;++i)
	{
		l[i]=i;
		while(tp>0&&st[tp]>=i-h[i]+1)
		{
			assert(l[st[tp]]<=l[i]);
			l[i]=l[st[tp--]];
		}
		st[++tp]=i;
	}
	tp=0;
	for(int i=m;i>=1;--i)
	{
		r[i]=i;
		while(tp>0&&st[tp]<=i+h[i]-1)
		{
			assert(r[st[tp]]>=r[i]);
			r[i]=r[st[tp--]];
		}
		st[++tp]=i;
	}
	tp=0;
	st[++tp]=1;
	for(int i=1;i<=m;++i)
	{
		dp[i]=dp[l[i]-1]+cost[i];
		if(tp)
			dp[i]=min(dp[i],dp[st[tp]-1]+cost[st[tp]]);
		while(tp>0&&r[st[tp]]<=i)
			--tp;
		if(i<m)
		{
// 			while(tp>0&&dp[st[tp]-1]+cost[st[tp]]>=dp[i]+cost[i+1]&&r[st[tp]]==r[i+1])
// 				--tp;
			if(tp==0||dp[i]+cost[i+1]<dp[st[tp]-1]+cost[st[tp]])
				st[++tp]=i+1;
		}
	}
	printf("%lld\n",dp[m]);
	return 0;
}