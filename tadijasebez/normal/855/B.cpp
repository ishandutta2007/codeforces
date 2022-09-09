#include <stdio.h>
const int N=100050;
const long long inf=4000000000ll*1000000000ll;
long long BIT[N];
int n;
long long max(long long a, long long b){ return a>b?a:b;}
void Init()
{
	int i;
	for(i=0;i<=n;i++) BIT[i]=-inf;
}
void Set(int index, long long val)
{
	for(index;index<=n;index+=index&-index) BIT[index]=max(BIT[index],val);
}
long long Get(int index)
{
	long long ans=-inf;
	for(index;index;index-=index&-index) ans=max(ans,BIT[index]);
	return ans;
}
long long DP[N][3];
long long a[N];
int main()
{
	int i;
	long long p,q,r;
	scanf("%i %lld %lld %lld",&n,&p,&q,&r);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	Init();
	for(i=1;i<=n;i++)
	{
		DP[i][0]=p*a[i];
		Set(i,DP[i][0]);
	}
	for(i=1;i<=n;i++)
	{
		DP[i][1]=q*a[i]+Get(i);
	}
	Init();
	for(i=1;i<=n;i++) Set(i,DP[i][1]);
	long long sol=-inf;
	for(i=1;i<=n;i++)
	{
		DP[i][2]=r*a[i]+Get(i);
		sol=max(sol,DP[i][2]);
	}
	printf("%lld\n",sol);
	return 0;
}