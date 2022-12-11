#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int a[max_n];
long long sum[max_n],s0[max_n],s1[max_n];
const int max_Ra=2e5+5;
long long Hash[max_Ra];
int Ra;
struct BIT
{
	int val[max_Ra];
	inline void clear()
	{
		for(int i=1;i<=Ra;++i)
			val[i]=0;
	}
	inline void modify(int k,int v)
	{
		assert(k>0);
		for(int i=k;i<=Ra;i+=i&(-i))
			val[i]+=v;
	}
	inline int query(int k)
	{
		assert(k<=Ra);
		int res=0;
		for(int i=k;i>0;i-=i&(-i))
			res+=val[i];
		return res;
	}
}B[2];
inline long long solve(int L,int R,long long v) // [L,R] is CC..CC PC...PC PP...PP, and sum of P subtract sum of C is not less than v.
{
	if(R-L+1==0)
	{
//		fprintf(stderr,"res=0\n");
		return 0;
	}
	B[0].clear(),B[1].clear();
	long long res=0;
	for(int i=L;i<=R-1;++i)
	{
		int pos=lower_bound(Hash+1,Hash+Ra+1,2*s1[i])-Hash;
		assert(Hash[pos]==2*s1[i]);
		int k=i&1;
		B[k].modify(pos,1);
		long long lim=sum[R]+sum[L-1]-2*s0[i]-v;
		pos=upper_bound(Hash+1,Hash+Ra+1,lim)-Hash-1;
		res+=B[k].query(pos);
	}
//	fprintf(stderr,"res=%lld\n",res);
	return res;
}
const int mod=998244353;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if(n==1)
		{
			int x;
			scanf("%d",&x);
			puts("1");
			continue;
		}
		Ra=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			sum[i]=sum[i-1]+a[i];
			if(i==1)
			{
				s0[i]=a[i];
				s1[i]=0;
			}
			else
			{
				s0[i]=s0[i-2]+a[i];
				s1[i]=s1[i-2]+a[i-1];
			}
			Hash[++Ra]=2*s1[i];
//			fprintf(stderr,"i=%d sum=%lld s0=%lld s1=%lld\n",i,sum[i],s0[i],s1[i]);
		}
		sort(Hash+1,Hash+Ra+1);
		Ra=unique(Hash+1,Hash+Ra+1)-Hash-1;
		long long ans=0;
		ans+=solve(1,n,1);
		ans+=solve(2,n,1-a[1]);
		ans+=solve(1,n-1,1+a[n]);
		ans+=solve(2,n-1,1-a[1]+a[n]);
		for(int i=1;i<=n;++i)
		{
			if(sum[i]>sum[n]-sum[i])
				++ans;
		}
		printf("%lld\n",ans%mod);
	}
	return 0;
}
/*
2
2
1 2
2
2 1
*/