#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
typedef long long ll;
const ll bas1=31,bas2=37;
const ll mod1=1000000007,mod2=998244353,B=1000000009;
char s[maxn],t[maxn];
ll xp1[maxn],xp2[maxn],hs1[maxn],hs2[maxn];
int n,len;
const int M=1000007;
struct HashTable
{
	int head[M],nxt[maxn],p;
	ll to[maxn];
	int val[maxn];
	void add(ll x,int y)
	{
		int u=x%M;
		++p;
		to[p]=x;val[p]=y;nxt[p]=head[u];head[u]=p;
	}
	int query(ll x)
	{
		int u=x%M;
		for(int i=head[u];i;i=nxt[i])if(to[i]==x)return val[i];
		return -1; 
	}
}ht;
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
int K[maxn],sz[maxn],le[maxn];
vector<int> g[maxn];
int main()
{
	scanf("%s",s+1);
	len=strlen(s+1);
	xp1[0]=xp2[0]=1;
	for(int i=1;i<=len;++i)
	{
		xp1[i]=xp1[i-1]*bas1%mod1;
		xp2[i]=xp2[i-1]*bas2%mod2;
		hs1[i]=(hs1[i-1]*bas1+s[i]-'a'+1)%mod1;
		hs2[i]=(hs2[i-1]*bas2+s[i]-'a'+1)%mod2;
	}
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int k;
		scanf("%d%s",&K[i],t+1);
		int m=strlen(t+1);
		le[i]=m;
		ll h1=0,h2=0;
		for(int j=1;j<=m;++j)
		{
			h1=(h1*bas1+t[j]-'a'+1)%mod1;
			h2=(h2*bas2+t[j]-'a'+1)%mod2;
		}
		ll H=h1*B+h2;
		ht.add(H,i);
		sz[m]++;
	}
	for(int L=1;L<=len;++L)if(sz[L])
	{
		for(int i=1;i+L-1<=len;++i)
		{
			ll H=query1(i,i+L-1)*B+query2(i,i+L-1);
			int t=ht.query(H);
			if(t!=-1)g[t].push_back(i);
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(g[i].size()<K[i])puts("-1");
		else
		{
			int ans=len;
			for(int j=0;j+K[i]-1<g[i].size();++j)
			{
				ans=min(ans,g[i][j+K[i]-1]-g[i][j]+le[i]);
			}
			printf("%d\n",ans);
		}
	}
}