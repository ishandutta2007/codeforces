#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define mpr(a,b) make_pair(a,b)
using namespace std;
ll gcd(ll a,ll b){if(!b)return a;return gcd(b,a%b);}
ll fastpow(ll a,ll p,ll mod)
{
	ll ans=1;
	while(p)
	{
		if(p&1)ans=ans*a%mod;
		a=a*a%mod;p>>=1;
	}
	return ans;
}
ll inv(ll x,ll mod){return fastpow(x,mod-2,mod);}
int n;
char s[1000005];
int fa[27],cnt[27],tmp[27];
int find(int x)
{
	if(fa[x]==x)return fa[x];
	return fa[x]=find(fa[x]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=26;++i)fa[i]=i;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		int len=strlen(s+1);
		memset(tmp,0,sizeof(tmp));
		for(int j=1;j<=len;++j)cnt[s[j]-'a'+1]++,tmp[s[j]-'a'+1]++;
		for(int j=1;j<=26;++j)
			for(int k=1;k<=26;++k)if(tmp[j]&&tmp[k]&&find(j)!=find(k))fa[find(j)]=find(k);
	}
	int ans=0;
	for(int i=1;i<=26;++i)if(find(i)==i&&cnt[i])ans++;
	cout<<ans<<endl;
}