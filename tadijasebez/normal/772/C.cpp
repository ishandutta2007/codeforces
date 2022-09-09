#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define ll long long
const int N=300050;
int gcd(int x, int y){ return x?gcd(y%x,x):y;}
vector<int> block[N];
int ban[N],dp[N],go[N];
int powmod(int x, int k, int mod)
{
	int ret=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;
	return ret;
}
int phi(int x)
{
	int sol=1;
	for(int i=2;i*i<=x;i++)
	{
		if(x%i) continue;
		sol*=i-1;x/=i;
		while(!(x%i)) x/=i,sol*=i;
	}
	if(x>1) sol*=x-1;
	return sol;
}
int mulinv(int a, int b)
{
	int t1=a,t2=b,t3;
	int v1=1,v2=0,v3;
	while(t2!=1)
	{
		int x=t1/t2;
		t3=t1-t2*x;
		v3=v1-v2*x;
		t1=t2;t2=t3;
		v1=v2;v2=v3;
	}
	return (v2+b)%b;
}
int inv(int a, int b, int mod)
{
	int g=gcd(a,mod);
	a/=g;b/=g;mod/=g;
	//int etf=phi(mod);
	//int ret=(ll)b*powmod(a,etf,mod)%mod;
	int ret=(ll)b*mulinv(a,mod)%mod;
	return ret;
}
int main()
{
	int n,m,i,j,x;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%i",&x),ban[x]=1;
	for(i=0;i<m;i++) if(!ban[i]) block[gcd(i,m)].pb(i);
	for(i=1;i<=m;i++)
	{
		dp[i]+=block[i].size();
		//printf("%i ",dp[i]);
		for(j=i*2;j<=m;j+=i) if(dp[j]<dp[i]) dp[j]=dp[i],go[j]=i;
	}
	int sol=0,taj=0;
	for(i=1;i<=m;i++) if(dp[i]>sol) sol=dp[i],taj=i;
	vector<int> ans;
	while(taj)
	{
		for(i=0;i<block[taj].size();i++) ans.push_back(block[taj][i]);
		taj=go[taj];
	}
	reverse(ans.begin(),ans.end());
	printf("%i\n",ans.size());
	printf("%i ",ans[0]);
	for(i=1;i<ans.size();i++) printf("%i ",inv(ans[i-1],ans[i],m));
	return 0;
}