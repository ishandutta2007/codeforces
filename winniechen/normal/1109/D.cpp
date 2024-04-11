#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 1000005
#define ll long long
#define mod 1000000007
int fac[N],inv[N],n,m,maxn,ans;
int q_pow(int x,int n){int ret=1;for(;n;n>>=1,x=(ll)x*x%mod)if(n&1)ret=(ll)ret*x%mod;return ret;}
int C(int n,int m){return (ll)fac[n]*inv[m]%mod*inv[n-m]%mod;}
int main()
{
	scanf("%d%d%*d%*d",&n,&m);maxn=max(n,m);fac[0]=1;
	for(int i=1;i<=maxn;i++)fac[i]=fac[i-1]*(ll)i%mod;inv[maxn]=q_pow(fac[maxn],mod-2);
	for(int i=maxn;i;i--)inv[i-1]=(ll)i*inv[i]%mod;
	for(int i=1;i<n;i++)if(i<=m)
	{
		int tmp=(ll)C(m-1,i-1)*fac[n-2]%mod*inv[n-i-1]%mod*q_pow(m,n-i-1)%mod;
		if(i!=n-1)tmp=(ll)tmp*(i+1)%mod*q_pow(n,n-i-2)%mod;(ans+=tmp)%=mod;
	}
	printf("%d\n",ans);
}



///