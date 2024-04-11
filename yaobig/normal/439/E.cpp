#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

ll fac[maxn+5],ifac[maxn+5],inv[maxn+5];
ll C(int n,int m)
{
	if(m<0 || n<m) return 0;
	return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}

vi fct[maxn+5];
int p[maxn+5],mu[maxn+5];
bool np[maxn+5];


int main()
{
	inv[1]=fac[0]=ifac[0]=1;
	rep(i,2,maxn) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	rep(i,1,maxn) fac[i]=fac[i-1]*i%mod;
	rep(i,1,maxn) ifac[i]=ifac[i-1]*inv[i]%mod;
	
	rep(i,1,maxn) for(int j=i;j<=maxn;j+=i) fct[j].pb(i);

	mu[1]=1; np[0]=np[1]=1;
	int num=0;
	rep(i,2,maxn)
	{
		if(np[i]==0)
		{
			p[++num]=i;
			mu[i]=-1;
		}
		rep(j,1,num)
		{
			ll v=1ll*i*p[j];
			if(v>maxn) break;
			np[v]=1;
			if(i%p[j]==0)
			{
				mu[v]=0;
				break;
			}
			mu[v]=-mu[i];
		}
	}

	int Q; scanf("%d",&Q);
	while(Q--)
	{
		int n,k; scanf("%d%d",&n,&k);
		ll ans=0;
		for(auto d: fct[n]) ans=(ans+1ll*mu[d]*C(n/d-1,k-1)%mod+mod)%mod;
		printf("%I64d\n",ans);
	}
	return 0;
}