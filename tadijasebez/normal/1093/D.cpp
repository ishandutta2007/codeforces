#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int mod=998244353;
const int N=300050;
vector<int> E[N];
int was[N],odd;
int cnt[2];
void DFS(int u, int f)
{
	cnt[f]++;
	was[u]=f+1;
	for(int v:E[u])
	{
		if(!was[v]) DFS(v,f^1);
		else if(was[v]==was[u]) odd=1;
	}
}
int pow(int x, int k){ int ans=1;for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ans=(ll)ans*x%mod;return ans;}
int main()
{
	int t;
	scanf("%i",&t);
	while(t--)
	{
		int n,m,u,v,i;
		scanf("%i %i",&n,&m);
		for(i=1;i<=n;i++) was[i]=0,E[i].clear();
		while(m--) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
		int ans=1;
		for(i=1;i<=n;i++) if(!was[i])
		{
			odd=cnt[0]=cnt[1]=0;
			DFS(i,0);
			if(odd) ans=0;
			else ans=(ll)ans*(pow(2,cnt[0])+pow(2,cnt[1]))%mod;
		}
		printf("%i\n",ans);
	}
	return 0;
}