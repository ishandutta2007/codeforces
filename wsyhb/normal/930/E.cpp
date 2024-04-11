#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int l[2][max_n],r[2][max_n];
const int max_R=6e5+5;
int Hash[max_R],lst[2][max_R],dp[2][max_R],R;
inline int trans(int x)
{
	return lower_bound(Hash+1,Hash+R+1,x)-Hash;
}
inline void check_max(int &a,int b)
{
	a=max(a,b);
}
const int mod=1e9+7;
inline void add(int &a,int b)
{
	a=a+b-(a+b>=mod?mod:0);
}
inline int qpow(int a,int n)
{
	int res=1;
	while(n)
	{
		if(n&1)
			res=1ll*res*a%mod;
		a=1ll*a*a%mod;
		n>>=1;
	}
	return res;
}
inline int get_sum(int a,int b)
{
	return a+b-(a+b>=mod?mod:0);
}
inline void sub(int &a,int b)
{
	a=a-b+(a<b?mod:0);
}
int main()
{
	int k,n[2];
	scanf("%d%d%d",&k,n,n+1);
	for(int t=0;t<=1;++t)
		for(int i=1;i<=n[t];++i)
		{
			scanf("%d%d",l[t]+i,r[t]+i);
			Hash[++R]=l[t][i];
			Hash[++R]=l[t][i]-1;
			Hash[++R]=r[t][i];
		}
	Hash[++R]=0;
	Hash[++R]=k;
	sort(Hash+1,Hash+R+1);
	R=unique(Hash+1,Hash+R+1)-Hash-1;
	for(int t=0;t<=1;++t)
		for(int i=1;i<=n[t];++i)
			check_max(lst[t][trans(r[t][i])],trans(l[t][i]));
	dp[0][1]=1;
	int sum[2]={1,0},pos[2]={0,0};
	for(int i=1;i<R;++i)
	{
		int v=(qpow(2,Hash[i+1]-Hash[i]-1)-1ll)*(sum[0]+sum[1])%mod;
		for(int t=0;t<=1;++t)
		{
			add(dp[t][i],sum[t^1]);
			add(dp[t][i+1],v);
		}
		sum[0]=sum[1]=get_sum(get_sum(sum[0],sum[1]),v);
		for(int t=0;t<=1;++t)
		{
			while(pos[t]+1<lst[t][i+1])
				sub(sum[t],dp[t][++pos[t]]);
		}
	}
	printf("%d\n",get_sum(sum[0],sum[1]));
	return 0;
}