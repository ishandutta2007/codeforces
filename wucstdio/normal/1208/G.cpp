#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll n,k,phi[1000005],prime[1000005],num;
bool flag[1000005];
void pre(ll n)
{
	phi[1]=1;
	flag[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!flag[i])
		{
			prime[++num]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=num&&prime[j]*i<=n;j++)
		{
			flag[i*prime[j]]=1;
			if(i%prime[j]==0)
			{
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			phi[i*prime[j]]=phi[i]*phi[prime[j]];
		}
	}
}
int main()
{
	scanf("%lld%lld",&n,&k);
	if(k==1)
	{
		printf("3\n");
		return 0;
	}
	pre(n);
	sort(phi+2,phi+n+1);
	ll ans=1;
	for(int i=2;i<=k+2;i++)
	  ans+=phi[i];
	printf("%lld\n",ans);
	return 0;
}