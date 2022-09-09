#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=100050;
const int K=205;
const int mod=1e9+7;
int add(int a, int b){ a+=b;return a>=mod?a-mod:a;}
int sub(int a, int b){ a-=b;return a<0?a+mod:a;}
int mul(int a, int b){ return (ll)a*b%mod;}
int st[K][K],F[K];
void Stirling()
{
	st[1][1]=1;
	for(int i=2;i<K;i++)
		for(int j=1;j<=i;j++)
			st[i][j]=add(st[i-1][j-1],mul(st[i-1][j],j));
	F[0]=1;
	for(int i=1;i<K;i++) F[i]=mul(F[i-1],i);
}
int n,k,g[N][K],h[N][K],sz[N];
vector<int> E[N];
void DFS(int u, int p)
{
	g[u][0]=2;
	for(int v:E[u]) if(v!=p)
	{
		DFS(v,u);
		for(int i=min(sz[v]+1,k);i>0;i--)
			g[v][i]=add(g[v][i],sub(g[v][i-1],i==1));
		for(int i=min(sz[u]+sz[v]+1,k);i>=0;i--)
		{
			int sum=0;
			for(int j=max(0,i-sz[u]);j<=min(i,sz[v]+1);j++)
			{
				sum=add(sum,mul(g[u][i-j],g[v][j]));
			}
			g[u][i]=sum;
		}
		sz[u]+=sz[v]+1;
	}
	for(int i=0;i<=min(sz[u],k);i++)
	{
		h[u][i]=g[u][i];
		for(int v:E[u]) if(v!=p)
		{
			h[u][i]=sub(h[u][i],g[v][i]);
		}
	}
}
int main()
{
	Stirling();
	scanf("%i %i",&n,&k);
	int u,v;
	for(int i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	DFS(1,0);
	int ans=0;
	for(int i=1;i<=k;i++)
	{
		int sum=0;
		for(int j=1;j<=n;j++)
			sum=add(sum,h[j][i]);
		ans=add(ans,mul(mul(F[i],st[k][i]),sum));
	}
	printf("%i\n",ans);
	return 0;
}