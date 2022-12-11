#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
typedef long long ll;
const ll bas1=31,bas2=37;
const ll mod1=998244353,mod2=1000000007,B=1000000009;
int n,m;
char s[maxn],t[maxn];
vector<int> pos[30];
ll h1[maxn],h2[maxn],xp1[maxn],xp2[maxn];
ll hs1[30],hs2[30];
ll gethash(int l,int r)
{
	ll x=h1[r]-h1[l-1]*xp1[r-l+1]%mod1;
    x=(x%mod1+mod1)%mod1;
    ll y=h2[r]-h2[l-1]*xp2[r-l+1]%mod2;
    y=(y%mod2+mod2)%mod2;
	return x*B+y; 
}
int go[30];
int main()
{
	xp1[0]=xp2[0]=1;
	for(int i=1;i<=200000;++i)
	{
		xp1[i]=xp1[i-1]*bas1%mod1;
		xp2[i]=xp2[i-1]*bas2%mod2;
	}
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)
	{
		h1[i]=(h1[i-1]*bas1%mod1+s[i]-'a'+1)%mod1;
		h2[i]=(h2[i-1]*bas2%mod2+s[i]-'a'+1)%mod2;
	}
	scanf("%s",t+1);
	for(int i=1;i<=m;++i)
	{
		pos[t[i]-'a'+1].push_back(i);
	}
	for(int j=1;j<=26;++j)
	{
		for(int i:pos[j])
		{
			hs1[j]=(hs1[j]+xp1[m-i])%mod1;
			hs2[j]=(hs2[j]+xp2[m-i])%mod2;
		}
	}
	vector<int> ans;
	for(int i=1;i<=n-m+1;++i)
	{
		bool yes=1;
		memset(go,0,sizeof(go));
		for(int j=1;j<=26;++j)if(pos[j].size())
		{
			int x=pos[j][0];
			int u=t[x]-'a'+1,v=s[i+x-1]-'a'+1;
			if(go[u]||go[v])
			{
				if(go[u]!=v||go[v]!=u)yes=0;
			}
			else
			{
				go[u]=v;go[v]=u;
			}
		}
		if(yes)
		{
			ll H1=0,H2=0;
			for(int j=1;j<=26;++j)
			{
				H1=(H1+hs1[j]*go[j]%mod1)%mod1;
				H2=(H2+hs2[j]*go[j]%mod2)%mod2;
			}
			ll H=H1*B+H2,T=gethash(i,i+m-1);
			if(H==T)ans.push_back(i);
		}
	}
	printf("%d\n",ans.size());
	for(int x:ans)printf("%d ",x);
}