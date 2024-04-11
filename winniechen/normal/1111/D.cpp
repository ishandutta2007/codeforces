#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
#include <map>
using namespace std;
#define N 100005
#define ll long long
#define mod 1000000007
map<pair<int ,int > ,int >mp;
int fac[N],inv[N],f[N],t[N],n,Q,w;char s[N];
int q_pow(int x,int n){int ret=1;for(;n;n>>=1,x=(ll)x*x%mod)if(n&1)ret=(ll)ret*x%mod;return ret;}
void ins(int x){for(int i=n;i>=x;i--)(f[i]+=f[i-x])%=mod;}
void del(int x){for(int i=x;i<=n;i++)(f[i]+=mod-f[i-x])%=mod;}
int calc(int x,int y)
{
	if(x>y)swap(x,y);if(x+y>(n>>1))return 0;if(mp.find(make_pair(x,y))!=mp.end())return mp[make_pair(x,y)];int ret=0;
	del(x),del(y);ret=f[(n>>1)-x-y];ins(x);ins(y);return mp[make_pair(x,y)]=(((ret<<1)%mod)+mod)%mod;
}
int main()
{
	scanf("%s%d",s+1,&Q);n=strlen(s+1);f[0]=fac[0]=1;
	for(int i=1;i<=n;i++)t[s[i]]++,fac[i]=(ll)i*fac[i-1]%mod;inv[n]=q_pow(fac[n],mod-2);
	for(int i=n;i;i--)inv[i-1]=(ll)i*inv[i]%mod;w=(ll)fac[n>>1]*fac[n>>1]%mod;
	for(int i=0;i<=128;i++)if(t[i])ins(t[i]),w=(ll)w*inv[t[i]]%mod;
	while(Q--)
	{
		int x,y;scanf("%d%d",&x,&y);
		if(s[x]==s[y])printf("%lld\n",(ll)w*f[n>>1]%mod);
		else printf("%lld\n",(ll)w*calc(t[s[x]],t[s[y]])%mod);
	}
}
//