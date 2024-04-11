#include<bits/stdc++.h>
using namespace std;
int k;
const int max_R=1e7+5;
bool mark_p[max_R];
int prime[max_R],cnt;
long long expo[max_R];
inline bool check(long long n)
{
	for(int i=1;i<=cnt;++i)
	{
		long long expo_now=0,t=n/prime[i];
		while(t)
		{
			expo_now+=t;
			t/=prime[i];
		}
		if(expo_now<expo[i])
			return false;
	}
	return true;
}
int c[max_R];
const int max_k=1e6+5;
int a[max_k];
int main()
{
	scanf("%d",&k);
	int R=0;
	long long sum=0;
	for(int i=1;i<=k;++i)
	{
		scanf("%d",a+i);
		R=max(R,a[i]);
		sum+=a[i];
		++c[a[i]];
	}
	for(int i=2;i<=R;++i)
		mark_p[i]=true;
	for(int i=2;i<=R;++i)
	{
		if(mark_p[i])
			prime[++cnt]=i;
		for(int j=1;j<=cnt&&i*prime[j]<=R;++j)
		{
			mark_p[i*prime[j]]=false;
			if(i%prime[j]==0)
				break;
		}
	}
	for(int i=R;i>=1;--i)
		c[i]+=c[i+1];
	for(int i=1;i<=cnt;++i)
	{
		int p=prime[i];
		for(int j=p;j<=R;j+=p)
		{
			int t=j,expo_now=0;
			while(t%p==0)
				t/=p,++expo_now;
			expo[i]+=1ll*expo_now*c[j];
		}
	}
	long long l=1,r=sum,res=sum+1;
	while(l<=r)
	{
		long long mid=(l+r)>>1;
		if(check(mid))
			res=mid,r=mid-1;
		else
			l=mid+1;
	}
	assert(res<=sum);
	printf("%lld\n",res);
	return 0;
}