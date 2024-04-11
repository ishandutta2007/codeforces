#include<bits/stdc++.h>
using namespace std;
int n,A,B,C,D,R;
unsigned int ans;
inline unsigned int f(unsigned int x)
{
	return ((A*x+B)*x+C)*x+D;
}
inline void calc(int p)
{
	int expo=0,now=n/p;
	while(now)
	{
		expo+=now;
		now/=p;
	}
	ans+=expo*f(p);
}
const int max_R=17320+5;
int prime[max_R],cnt;
const int max_B=5e4+5;
bool mark_p[max_B];
inline void init()
{
	for(int i=2;i<=R;++i)
		mark_p[i]=true;
	for(int i=2;i<=R;++i)
	{
		if(mark_p[i])
		{
			prime[++cnt]=i;
			calc(i);
		}
		for(int j=1;j<=cnt&&i*prime[j]<=R;++j)
		{
			mark_p[i*prime[j]]=false;
			if(i%prime[j]==0)
				break;
		}
	}
}
int main()
{
	scanf("%d%d%d%d%d",&n,&A,&B,&C,&D);
	R=sqrt(n);
	init();
	int now=R;
	const int B=5e4;
	while(now<n)
	{
		int l=now+1,r=min(now+B,n);
		for(int i=l;i<=r;++i)
			mark_p[i-now]=true;
		for(int i=1;i<=cnt;++i)
		{
			int p=prime[i];
			for(int j=(l+p-1)/p*p;j<=r;j+=p)
				mark_p[j-now]=false;
		}
		for(int i=l;i<=r;++i)
		{
			if(mark_p[i-now])
				calc(i);
		}
		now=r;
	}
	printf("%u\n",ans);
	return 0;
}