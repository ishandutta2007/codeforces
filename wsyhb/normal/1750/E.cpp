#include<bits/stdc++.h>
using namespace std;
int n;
const int max_n=2e5+5;
char s[max_n];
int sum[max_n],st[max_n],Left[max_n],Right[max_n],R;
struct BIT
{
	long long val[max_n<<1];
	inline void add(int k,int v)
	{
		for(int i=k+n+1;i<=R;i+=i&(-i))
			val[i]+=v;
	}
	inline long long query(int k)
	{
		long long res=0;
		for(int i=k+n+1;i>0;i-=i&(-i))
			res+=val[i];
		return res;
	}
}B_cnt,B_sum;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&n,s+1);
		long long ans=0;
		for(int i=1;i<=n;++i)
		{
			sum[i]=sum[i-1]+(s[i]=='('?1:-1);
			ans+=1ll*i*sum[i];
		}
		int tp=0;
		st[0]=-1;
		for(int i=0;i<=n;++i)
		{
			while(tp>0&&sum[st[tp]]>sum[i])
				--tp;
			Left[i]=st[tp];
			st[++tp]=i;
		}
		tp=0,st[0]=n+1;
		for(int i=n;i>=0;--i)
		{
			while(tp>0&&sum[st[tp]]>=sum[i])
				--tp;
			Right[i]=st[tp];
			st[++tp]=i;
		}
		for(int i=0;i<=n;++i)
			ans-=((Right[i]-i+0ll)*(i-Left[i])-1)*sum[i];
		R=n<<1|1;
		for(int i=n;i>=0;--i)
		{
			ans+=B_cnt.query(sum[i])*sum[i]-B_sum.query(sum[i]);
			B_cnt.add(sum[i],1),B_sum.add(sum[i],sum[i]);
		}
		printf("%lld\n",ans);
		for(int i=1;i<=R;++i)
			B_cnt.val[i]=B_sum.val[i]=0;
	}
	return 0;
}