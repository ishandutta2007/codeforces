#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
typedef long long ll;
const ll bas1=31,bas2=37;
const ll mod1=998244353,mod2=1000000007;
const ll B=1000000009;
ll xp1[maxn],xp2[maxn];
int n,m;
char t[maxn],s[maxn];
map<ll,ll> g[maxn];
vector<int> v;
ll hs1[maxn],hs2[maxn];
ll Lcnt[maxn],Rcnt[maxn];
ll query1(int l,int r)
{
    ll x=hs1[r]-hs1[l-1]*xp1[r-l+1]%mod1;
    x=(x%mod1+mod1)%mod1;
    return x;
}
ll query2(int l,int r)
{
    ll x=hs2[r]-hs2[l-1]*xp2[r-l+1]%mod2;
    x=(x%mod2+mod2)%mod2;
    return x;
}
int main()
{
	xp1[0]=xp2[0]=1;
	for(int i=1;i<=200000;++i)
	{
		xp1[i]=xp1[i-1]*bas1%mod1;
		xp2[i]=xp2[i-1]*bas2%mod2;
	}
	scanf("%s",t+1);
	m=strlen(t+1);
	for(int i=1;i<=m;++i)
	{
		hs1[i]=(hs1[i-1]*bas1%mod1+t[i]-'a'+1)%mod1;
		hs2[i]=(hs2[i-1]*bas2%mod2+t[i]-'a'+1)%mod2;
	}
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		int len=strlen(s+1);
		ll h1=0,h2=0;
		for(int j=1;j<=len;++j)
		{
			h1=(h1*bas1%mod1+s[j]-'a'+1)%mod1;
			h2=(h2*bas2%mod2+s[j]-'a'+1)%mod2;
		}
		g[len][h1*B+h2]++;
	}
	for(int i=1;i<=200000;++i)if(g[i].size())v.push_back(i);
	for(int i=1;i<=m;++i)
	{
		for(int len:v)if(i>=len)
		{
			int l=i-len+1,r=i;
			ll hval=query1(l,r)*B+query2(l,r);
			if(!g[len].count(hval))continue;
			ll num=g[len][hval];
			Lcnt[l]+=num;Rcnt[r]+=num;
		}
	}
	ll ans=0;
	for(int i=1;i<m;++i)
	{
		ans+=Rcnt[i]*Lcnt[i+1];
	}
	printf("%lld\n",ans);
}