#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int max_n=2e5+5;
int inv[max_n],prime[max_n],tot,mp[max_n];
bool mark_p[max_n];
inline void init(int n)
{
	inv[1]=1;
	for(int i=2;i<=n;++i)
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=n;++i)
		mark_p[i]=true;
	tot=0;
	for(int i=2;i<=n;++i)
	{
		if(mark_p[i])
		{
			prime[++tot]=i;
			mp[i]=i;
		}
		for(int j=1;j<=tot&&i*prime[j]<=n;++j)
		{
			mark_p[i*prime[j]]=false;
			mp[i*prime[j]]=prime[j];
			if(i%prime[j]==0)
				break;
		}
	}
}
int End[max_n<<1],Last[max_n],Next[max_n<<1],Len1[max_n<<1],Len2[max_n<<1],E;
inline void add_edge(int a,int b,int x,int y)
{
	End[++E]=b,Next[E]=Last[a],Last[a]=E,Len1[E]=x,Len2[E]=y;
	End[++E]=a,Next[E]=Last[b],Last[b]=E,Len1[E]=y,Len2[E]=x;
}
int val[max_n],cnt[max_n],mn[max_n];
inline void div(int x)
{
	while(x>1)
	{
		int p=mp[x];
		--cnt[p];
		mn[p]=min(mn[p],cnt[p]);
		x/=p;
	}
}
inline void mul(int x)
{
	while(x>1)
	{
		int p=mp[x];
		++cnt[p];
		mn[p]=min(mn[p],cnt[p]);
		x/=p;
	}
}
void dfs(int x,int fa)
{
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
		{
			val[y]=1ll*val[x]*inv[Len1[i]]%mod*Len2[i]%mod;
			mul(Len2[i]),div(Len1[i]);
			dfs(y,x);
			mul(Len1[i]),div(Len2[i]);
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
//		assert(false); // clear
		int n;
		scanf("%d",&n);
		init(n);
		for(int k=1;k<=n-1;++k)
		{
			int i,j,x,y;
			scanf("%d%d%d%d",&i,&j,&x,&y);
			add_edge(i,j,x,y);
		}
		val[1]=1;
		dfs(1,0);
		int sum=0;
		for(int i=1;i<=n;++i)
			sum=(sum+val[i])%mod;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=-mn[i];++j)
				sum=1ll*sum*i%mod;
		printf("%d\n",sum);
		E=0;
		for(int i=1;i<=n;++i)
			Last[i]=cnt[i]=mn[i]=0;
	}
	return 0;
}