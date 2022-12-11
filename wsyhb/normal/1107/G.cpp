#include<bits/stdc++.h>
using namespace std;
const int max_n=3e5+5;
int d[max_n],c[max_n],delta[max_n],Left[max_n],Right[max_n],st[max_n],tp,Log[max_n];
long long sum[max_n],Min[19][max_n],Max[19][max_n];
inline long long query_max(int l,int r)
{
	int k=Log[r-l+1];
	return max(Max[k][l],Max[k][r-(1<<k)+1]);
}
inline long long query_min(int l,int r)
{
	int k=Log[r-l+1];
	return min(Min[k][l],Min[k][r-(1<<k)+1]);
}
int main()
{
	int n,a;
	scanf("%d%d",&n,&a);
	for(int i=1;i<=n;++i)
		scanf("%d%d",d+i,c+i);
	for(int i=1;i<=n-1;++i)
		delta[i]=d[i+1]-d[i];
	st[0]=0;
	for(int i=1;i<=n-1;++i)
	{
		while(tp>0&&delta[st[tp]]<=delta[i])
			--tp;
		Left[i]=st[tp];
		st[++tp]=i;
	}
	st[0]=n,tp=0;
	for(int i=n-1;i>=1;--i)
	{
		while(tp>0&&delta[st[tp]]<=delta[i])
			--tp;
		Right[i]=st[tp];
		st[++tp]=i;
	}
	Log[0]=-1;
	for(int i=1;i<=n;++i)
	{
		sum[i]=sum[i-1]+(a-c[i]);
		Min[0][i]=Max[0][i]=sum[i];
		Log[i]=Log[i>>1]+1;
	}
	Log[n+1]=Log[(n+1)>>1]+1;
	for(int i=1;i<=Log[n+1];++i)
		for(int j=0;j+(1<<i)-1<=n;++j)
		{
			Min[i][j]=min(Min[i-1][j],Min[i-1][j+(1<<(i-1))]);
			Max[i][j]=max(Max[i-1][j],Max[i-1][j+(1<<(i-1))]);
		}
	long long ans=0;
	for(int i=1;i<=n-1;++i)
		ans=max(ans,-1ll*delta[i]*delta[i]+query_max(i+1,Right[i])-query_min(Left[i],i-1));
	for(int i=1;i<=n;++i)
		ans=max(ans,1ll*a-c[i]);
	printf("%lld\n",ans);
	return 0;
}