#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int t,n,m,dep[4000005],mind[4000005],res[4000005],top;
ll a[4000005];
void del(int x)
{
	if(!a[x<<1]&&!a[x<<1|1])
	{
		a[x]=0;
		mind[x]=dep[x]-1;
		return;
	}
	if(a[x<<1]>a[x<<1|1])
	{
		a[x]=a[x<<1];
		del(x<<1);
	}
	else
	{
		a[x]=a[x<<1|1];
		del(x<<1|1);
	}
	mind[x]=min(mind[x<<1],mind[x<<1|1]);
}
int calc(int x)
{
	if(!a[x<<1]&&!a[x<<1|1])return mind[x];
	return calc(x<<1|(a[x<<1|1]>a[x<<1]));
}
void solve(int x)
{
	if(!a[x])return;
	while(calc(x)>m)res[++top]=x,del(x);
	solve(x<<1);
	solve(x<<1|1);
}
int main()
{
	for(int i=1;i<=4000000;i++)dep[i]=dep[i>>1]+1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<(1<<n);i++)scanf("%lld",&a[i]);
		for(int i=(1<<n);i<(1<<(n+1));i++)a[i]=0;
		for(int i=1;i<(1<<n);i++)mind[i]=n;
		top=0;
		solve(1);
		ll sum=0;
		for(int i=1;i<(1<<m);i++)sum+=a[i];
		printf("%lld\n",sum);
		for(int i=1;i<=top;i++)printf("%d ",res[i]);
		printf("\n");
	}
	return 0;
}