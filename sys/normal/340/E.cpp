#include <bits/stdc++.h>
using namespace std;
const int Maxn=2000005,p=1e9+7;
long long dp[Maxn],sum[Maxn],val[Maxn],fac[Maxn],inv[Maxn];
bool sure[Maxn],vis[Maxn];
long long fast_pow(long long x,long long y)
{
	long long ans=1,now=x;
	while(y)
	{
		if(y&1) ans=(ans*now)%p;
		now=(now*now)%p;
		y>>=1;
	}
	return ans;
}
void init(int k,int q)
{
	fac[0]=1;
	for(int i=1;i<=k;i++)
		fac[i]=fac[i-1]*i%p;
	inv[k]=fast_pow(fac[k],p-2);
	for(int i=k-1;i>=0;i--)
		inv[i]=inv[i+1]*(i+1)%p;
	for(int i=0;i<=q;i++)
		dp[i]=(fac[q]*inv[i]%p*inv[q-i]%p*fac[k-i]%p*((i%2)?-1:1)%p+p)%p;
	sum[0]=dp[0];
	for(int i=1;i<=q;i++)
		sum[i]=(sum[i-1]+dp[i])%p;
}
int ans,k,q,n;
void read(long long &x)
{
	int f=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x*=10,x+=ch-'0',ch=getchar();}
	x*=(f==1?-1:1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&val[i]);
		if(val[i]==-1) k++;
		else
			sure[val[i]]=vis[i]=true;
	}
	for(int i=1;i<=n;i++)
		if(!sure[i]&&!vis[i]) q++;
	init(k,q);
	printf("%d",sum[q]);
	return 0;
}