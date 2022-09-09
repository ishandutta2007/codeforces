#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
const int N=200050;
struct BIT
{
	int sum[N];
	void init(){ for(int i=0;i<N;i++) sum[i]=0;}
	BIT(){ init();}
	void Set(int i, int f){ for(;i<N;i+=i&-i) sum[i]+=f;}
	int Get(int i){ int ans=0;for(;i;i-=i&-i) ans+=sum[i];return ans;}
	int Get(int l, int r){ return Get(r)-Get(l-1);}
} T,C;
int pow(int x, int k){ int ans=1;for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ans=(ll)ans*x%mod;return ans;}
int inv(int x){ return pow(x,mod-2);}
int F[N],a[N],l[N],r[N];
int Count(int n)
{
	int ans=(ll)(n-1)*n%mod*inv(2)%mod;
	ans=(ll)ans*ans%mod;
	return (ll)ans*F[n-2]%mod;
}
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) C.Set(i,1);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		if(a[i]!=-1) C.Set(a[i],-1);
	}
	F[0]=1;for(i=1;i<N;i++) F[i]=(ll)F[i-1]*i%mod;
	for(i=1;i<=n;i++) l[i]=l[i-1]+(a[i]==-1);
	for(i=n;i>=1;i--) r[i]=r[i+1]+(a[i]==-1);
	int ans=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]!=-1)
		{
			ans+=(ll)T.Get(a[i]+1,n)*F[l[n]]%mod;
			if(ans>=mod) ans-=mod;
			T.Set(a[i],1);
			int lo=C.Get(1,a[i]-1);
			int hi=C.Get(a[i]+1,n);
			ans+=(ll)hi*l[i]%mod*F[l[n]-1]%mod;
			if(ans>=mod) ans-=mod;
			ans+=(ll)lo*r[i]%mod*F[l[n]-1]%mod;
			if(ans>=mod) ans-=mod;
		}
	}
	ans+=Count(l[n]);
	if(ans>=mod) ans-=mod;
	ans=(ll)ans*inv(F[l[n]])%mod;
	printf("%i\n",ans);
	return 0;
}